ARG1="$1"
COUNT=0
ACTU=0
TOTAL=0
MOY=0
TOP=0;
MIN=100000000;
if [[ "$ARG1" = "color" ]]
	then
	/bin/echo -n `ruby -e "puts (-5..25).to_a.shuffle.join(' ')"` > ttrasacc_tmp.txt
	/bin/echo -n "./push_swap \"" > ttrasacc_try.sh
	/bin/cat ttrasacc_tmp.txt >> ttrasacc_try.sh
	/bin/echo -n "\" | ./checker -v \"" >> ttrasacc_try.sh
	/bin/cat ttrasacc_tmp.txt >> ttrasacc_try.sh
	/bin/echo "\"" >> ttrasacc_try.sh
	cat ttrasacc_try.sh
	read
	bash ttrasacc_try.sh
	rm ttrasacc_try.sh
	rm ttrasacc_tmp.txt
fi

if [[ "$ARG1" = "count" ]]
	then
		echo "COUNT  |  ACTU   |  MOY"
		while [ $COUNT -lt 75 ]
		do
			/bin/echo -n `ruby -e "puts (0..100).to_a.shuffle.join(' ')"` > ttrasacc_tmp.txt
			/bin/echo -n "./push_swap \"" > ttrasacc_try.sh
			/bin/cat ttrasacc_tmp.txt >> ttrasacc_try.sh
			/bin/echo "\"" >> ttrasacc_try.sh
			bash ttrasacc_try.sh > tmp.txt
			COUNT=$(($COUNT + 1))
			ACTU=$(cat tmp.txt | wc -l)
			if [[ $MIN -gt $ACTU ]]
				then
				MIN=$(($ACTU))
			fi
			if [[ $MAX -lt $ACTU ]]
				then
				MAX=$(($ACTU))
			fi
			TOTAL=$(($TOTAL + $ACTU))
			MOY=$(($TOTAL / $COUNT))
			printf "%-5s  |  %-6s |  %-5s\n" $COUNT $ACTU $MOY
		done
	echo "=========="
	echo "MIN :" $MIN
	echo "MAX :" $MAX
	echo "MOY :" $MOY
	rm ttrasacc_try.sh
	rm ttrasacc_tmp.txt	
fi
