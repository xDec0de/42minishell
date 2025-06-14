#!/bin/bash

# Check if we have permissions first
if [ $(id -u) -ne 0 ]
	then echo Root or sudo permissions are required to run this script.
	exit
fi

setup () {

	install_cmd=$1
	check_command=$2
	display_name=$3

	if ! eval "$check_command" > /dev/null 2>&1; then
		echo "$display_name not installed. Install? [y/n]"
		read -r answer
		if [[ "$answer" == "y" || "$answer" == "Y" ]]; then
			$install_cmd
		else
			echo "Skipping install of $display_name."
		fi
	else
		echo "$display_name is installed."
	fi
}

# Setup Makefile
setup "apt install -y make" "make -v" "Makefile"

# Setup readline library
setup "apt-get install -y libreadline-dev" "dpkg -s libreadline-dev" "libreadline-dev"

# Setup Python (For norminette)
setup "apt install -y python3" "python3 --version" "[Optional] Python 3 (For norminette)"

# Setup Pip (For norminette)
setup "apt install -y python3-pip" "pip3 --version" "[Optional] Pip (For norminette)"

# Setup Norminette
setup "pip3 install norminette --break-system-packages" "command norminette -v" "[Optional] Norminette (GLOBAL INSTALL)"

# Setup Unity
setup "git submodule update --init --recursive" "ls -A test/unity/src" "[Optional] Unity"

# Setup lcov
setup "apt install -y lcov" "lcov -v" "[Optional] lcov"
