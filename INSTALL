Here's a basic `INSTALL` file template tailored to your CUDA Edge Detection project, which you can adjust according to your specific setup and requirements. This file will guide users through the process of cloning the repository, setting up their environment, and building the project.

```
# CUDA Edge Detection - Installation Guide

## Overview

This document provides instructions for installing and running the CUDA Edge Detection project, which utilizes NVIDIA GPUs for efficient image processing.

## Prerequisites

Before you begin, ensure you have the following installed on your system:
- NVIDIA GPU with CUDA Compute Capability 3.5 or higher
- CUDA Toolkit (version 10.1 or later recommended)
- GNU Make

## Cloning the Repository

1. Open a terminal.
2. Clone the repository using Git:
   ```
   git clone https://github.com/gambiTarun/CUDA-Edge-Detection.git
   ```
3. Navigate to the project directory:
   ```
   cd CUDA-Edge-Detection
   ```

## Building the Project

1. From the project directory, compile the program using the included Makefile:
   ```
   make all
   ```
   This command will invoke `nvcc` to compile the CUDA code and generate the executable.

## Running the Program

After building the project, you can run the edge detection algorithm on your images:

### Using `run.sh` Script

1. Make sure the `run.sh` script is executable:
   ```
   chmod +x run.sh
   ```
2. Run the script with optional command-line arguments for your program:
   ```
   ./run.sh [arguments]
   ```

### Direct Execution

Alternatively, you can directly execute the compiled program:
```
./bin/filterEdgeDetection [arguments]
```

Replace `[arguments]` with the appropriate command-line arguments for your program, such as the path to the input image.

## Additional Information

For more details on using the program and specifying command-line arguments, please refer to the `README.md` file in the project directory.

## License

This project is licensed under the GNU General Public License. For more information, see the `LICENSE` file in the project directory.

## Support

For questions or issues, please open an issue on the project's GitHub repository.

Thank you for using CUDA Edge Detection!