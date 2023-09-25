# Open the text file for reading
with open('output.txt', 'r') as text_file:
    text_data = text_file.read()

# Encode the text as binary data (e.g., UTF-8 encoding)
binary_data = text_data.encode('utf-8')

# Open a binary file for writing
with open('output.bin', 'wb') as binary_file:
    binary_file.write(binary_data)

print("Text file converted to raw binary data and saved to 'output.bin'.")