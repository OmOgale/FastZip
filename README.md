# Zippy

The simplest and quickest way to zip and unzip your text files!!! :) <br />
<strong> Utilizes the Huffman Coding Algorithm and achieves greater than a 2:1 compression ratio.</strong> <br />
<strong> *Extremely fast compression and decompression due to use of concurrent parallel processing.* </strong> <br />
*Compiled using CMake with the clang compiler.*

`Initial Steps to use Zippy:`

Containerized using Docker with multi-platform/architecture support using <a href="https://github.com/docker/buildx">buildx</a>.

> Steps to work with Docker:
> 1. Ensure Docker is installed on your machine https://www.docker.com/get-started/. Have basic knowledge of commands like <code>docker images</code>, <code>docker ps</code>, etc.
> 2. Run <code>docker pull oogale/zippy</code> in the terminal.
> 3. Verify if present by running <code>docker images</code>.
> 4. To run the shell and work as if you were in a terminal: <code>docker run -it IMAGE-ID sh</code>
> 5. To send files to the container: <code>docker create -v /path/on/host:/path/to/container-dir IMAGE-ID</code>
> 6. To copy compressed files/decoded files from the container to your local fs, run <code>docker cp your-container-name:/path/to/file-on-container /path/on/host</code>


<strong>OR!!</strong>

> Steps to Clone:
> 1. Clone the repo.
> 2. In the terminal, run <code>bash run.sh</code> to build the <code>Zippy</code> executable.</li>
> 3. (IF NOT USING DOCKER) you can run <code>bash download.sh</code> if you want to save the compressed/decoded files to your machine.
> *NOTE: Could run into issues with C++ compilation, especially on a different platform architecture.*

`How to run Zippy in the terminal:`
<ul> Options:
  <li><code>./Zippy -encode "text filename/filepath"</code></li>
  <li><code>./Zippy -decode "binary filename/filepath"</code></li>
</ul>

<img src="https://bunnyacademy.b-cdn.net/what-is-docker.png" alt="drawing" width="150" align="left"/>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1200px-ISO_C%2B%2B_Logo.svg.png" alt="drawing" width="100" align="left"/>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Python-logo-notext.svg/800px-Python-logo-notext.svg.png" alt="drawing" width="100" align="left"/>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/Gnu-bash-logo.svg/2560px-Gnu-bash-logo.svg.png" alt="drawing" width="200" align="left"/>
