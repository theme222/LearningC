# Find the first .cpp file in the current directory
FILENAME="main"

# Export the FILENAME as an environment variable
export FILENAME

clear ; g++ "$FILENAME.cpp" -o $FILENAME ; echo " - Ready - " ; "./$FILENAME"