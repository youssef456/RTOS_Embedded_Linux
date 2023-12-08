#!/bin/sh

# Set the path to your application in the root filesystem
APP_PATH="/usr/bin/rtos"

# Check if the application exists
if [ -x "$APP_PATH" ]; then
    # Run your application
    echo "Running RTOS..."
    $APP_PATH
else
    echo "Error: RTOS executable not found at $APP_PATH"
fi

