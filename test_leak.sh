printf "\e[32m"
make
while true; do
    printf "\e[32mTest ?(Yy/Nn)"
	read -p "" yn
    case $yn in
        [Yy]* ) 
			printf "\e[94m"
			valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --verbose \
			 --log-file=valgrind-out.txt ./minishell
			printf "\e[91m\n\n\n------------VALGRIND OUTPUT\n"
			leak=`grep -A 5 "LEAK SUMMARY" valgrind-out.txt | grep -Po '^.{10}\K.*'`
			printf "\e[91m$leak"
			printf "\n"
			error=`grep "ERROR SUMMARY" valgrind-out.txt | grep -Po '.{10}\K.*'`
			printf "\e[91m$error"
			printf "\n\n";;
        [Nn]* ) exit;;
        * ) printf "\e[32mpakompri" && printf "\n";;
    esac
done
