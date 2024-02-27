#!/bin/bash

# Step 1: Clean the previous build (Optional)
echo "Cleaning previous builds..."
make clean

# Step 2: Compile the program using the Makefile
echo "Compiling the program..."
make all

# Step 3: Run the compiled program
# Replace 'YourExecutableName' with the actual name of the executable defined in your Makefile
echo "Running the program..."
./bin/filterEdgeDetection
