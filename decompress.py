import concurrent.futures
import sys

if len(sys.argv) < 2:
    sys.exit(1)

def process_chunk(chunk):
    result = ""
    search_str = ""

    for bit in chunk:
        search_str += bit
        if search_str in encoding_dict:
            result += encoding_dict[search_str]
            search_str = ""

    return result

def parallel_processing(binary_string, chunk_size = 1000):
    chunks = [binary_string[i:i+chunk_size] for i in range(0, len(binary_string), chunk_size)]

    with concurrent.futures.ThreadPoolExecutor() as executor:
        results = list(executor.map(process_chunk, chunks))

    return ''.join(results)

def is_binary(file_name):
        try:
            with open(file_name, "tr") as check_file:
                check_file.read()
                return False
        except Exception:
            return True

file_name = sys.argv[1]

if not is_binary(file_name):
    print("Please verify if the input is a bin file")
    sys.exit(1)

with open(file_name, "rb") as file:

    encoding_length_bytes = file.read(3)

    # Convert the bytes to an integer (assuming big-endian byte order)
    result_int = int.from_bytes(encoding_length_bytes, byteorder='big')

    map_string = (file.read(result_int)).decode('utf-8')

    pairs = map_string[1:].split('|')[:-1]
    encoding_dict = {}
    
    for pair in pairs:
        key, value = pair.split(':')
        encoding_dict[key] = value

    binary_content = file.read()
    binary_string = ''.join(format(byte, '08b') for byte in binary_content)
    result = parallel_processing(binary_string)

with open("decoded.txt", "w") as decoded_file:
    decoded_file.write(result)

