#!/bin/bash

# Check if we have permissions first
if [ $(id -u) -ne 0 ]; then
	echo Root or sudo permissions are required to run this script.
	exit 1
fi

# Flags

AUTO_YES=false
OPTIONALS=false

for arg in "$@"; do
	if [ "$arg" == "-y" ]; then
		AUTO_YES=true
	elif [ "$arg" == "-optional" ]; then
		OPTIONALS=true
	else
		echo "Usage: sudo $0 [-y] [-optional]"
		exit 2
	fi
done

# Function to check and install dependencies
setup () {

	install_cmd=$1
	check_command=$2
	display_name=$3

	if ! eval "$check_command" > /dev/null 2>&1; then
		if [ "$AUTO_YES" = false ]; then
			echo "$display_name not installed. Install? [y/n]"
			read -r answer
			if [[ "$answer" == "y" || "$answer" == "Y" ]]; then
				$install_cmd
			else
				echo "Skipping install of $display_name."
			fi
		else
			$install_cmd
		fi
	else
		echo "$display_name is installed."
	fi
}

# Setup Makefile
setup "apt install -y make" "make -v" "Makefile"

# Setup readline library
setup "apt-get install -y libreadline-dev" "dpkg -s libreadline-dev" "libreadline-dev"

if [ "$OPTIONALS" = true ]; then
	# Setup Python (For norminette)
	setup "apt install -y python3" "python3 --version" "[Optional] Python 3 (For norminette)"

	# Setup Pip (For norminette)
	setup "apt install -y python3-pip" "pip3 --version" "[Optional] Pip (For norminette)"

	# Setup Norminette
	setup "pip3 install norminette --break-system-packages" "command norminette -v" "[Optional] Norminette (GLOBAL INSTALL)"

	# Setup Valgrind
	setup "apt install -y valgrind" "valgrind --version" "[Optional] Valgrind"

	# Setup lcov
	setup "apt install -y lcov" "lcov -v" "[Optional] lcov"
fi

if make -v > /dev/null 2>&1 && dpkg -s libreadline-dev > /dev/null 2>&1; then
	make
else
	echo Could not make project. Missing required dependencies.
fi
