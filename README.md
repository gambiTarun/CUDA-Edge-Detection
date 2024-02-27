# CUDA-Edge-Detection

## Overview

This project implements an edge detection algorithm using CUDA, allowing for efficient processing of images on NVIDIA GPUs. The core functionality is encapsulated in a CUDA program that applies an edge detection filter to input images, highlighting the edges and contours within those images.

<div style="display: flex;">
    <img src="./data/sequences/1.pgm" alt="Original Image" style="float: center; width: 45%; margin-right: 5%;" />
    <img src="./data/sequences/1_processed.pgm" alt="Processed Image" style="float: center; width: 45%; margin-right: 5%;" />
</div>

## Prerequisites

- NVIDIA GPU with CUDA Compute Capability 3.5 or higher.
- CUDA Toolkit installed (version 10.1 or later recommended).
- GNU Make.

## Building the Project

The project includes a `Makefile` for easy compilation of the CUDA program. To build the project, follow these steps:

1. Navigate to the project directory where the `Makefile` is located.
2. Run the command `make all` to compile the program. The `Makefile` will invoke the appropriate `nvcc` commands to compile the CUDA code.

## Running the Program

After building the project, you can run the compiled executable directly, or use the provided `run.sh` script for convenience.

### Using `run.sh`

The `run.sh` script automates the process of cleaning, building, and running the program. To use it, follow these steps:

1. Ensure `run.sh` is executable by running `chmod +x run.sh`.
2. Execute the script by running `./run.sh`.

The script will clean previous builds, compile the program using the `Makefile`, and then run the resulting executable.

### Direct Execution

To run the program directly, execute the compiled executable from the command line after building. The executable name will depend on the target specified in the `Makefile`.

## Input and Output

- **Input:** Specify the input image file as a command-line argument to the program.
- **Output:** The program will generate an output image with the edges detected, saving it to a specified location.

## License

GNU GENERAL PUBLIC LICENSE

## Acknowledgments

- This project uses the [CUDA repository template](https://github.com/PascaleCourseraCourses/CUDAatScaleForTheEnterpriseCourseProjectTemplate)
