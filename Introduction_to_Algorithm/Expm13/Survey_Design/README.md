# survey-design
This project uses the Ford Fulkerson method to discover a feasible circulation in a network flow constructed by reading the amazon-meta.txt dataset. The program receives as the input the percentage to be applied to each client which indicates how many surveys each user is willing to answer besides the surveys already answered and produces as the output the percentage that indicates the maximum amount of surveys each product can still receive given the percentage applied to each user.
## How to execute
Just type in the terminal:
```
$ chmod +x run_tests.sh
$ ./run_tests.sh
```
The above command downloads the amazon-meta.txt dataset, generates a normalized dataset with 0.1% and 1% of the entire dataset and executes the program over the dataset with 0.1% data and some predefined parameters configuration. If you want to change the parameters and the dataset, you just need to edit the run_parser.sh and change the values.
