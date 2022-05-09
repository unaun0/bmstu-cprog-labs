# C programming

### Content

1. [First semester](#first_sem_c)  
	* [Laboratory works](#lab_works_1c)     
2. [Second semester](#second_sem_c)    
	* [Laboratory works](#lab_works_2c)   
3. [Functional testing automation](#func_tests_c).   
	* Bash-scripts 


<a name="first_sem_c"></a>	
## [First semester](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_1)
<a name="lab_works_1c"></a>	
#### Laboratory works

* [Lab №1](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_1/lab_01)


* [Lab №2](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_1/lab_02) 


* [Lab №3](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_1/lab_03)


* [Lab №4](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_1/lab_04)


* [Lab №5](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_1/lab_05)


<a name="second_sem_c"></a>	
## [Second semester](https://github.com/unaun0/bmstu-cprog-labs/tree/main/sem_2)
<a name="lab_works_2c"></a>	
#### Laboratory works


Empty now..

<a name="func_tests_c"></a>	
##  [Functional testing automation](https://github.com/unaun0/bmstu-cprog-labs/tree/main/testing_scripts)

###### Bash-scripts:

* Scripts for debug and release builds: `build_release.sh`, `build_debug.sh`.


* Side file cleanup script: `clean.sh`.


* Comparator to compare two text files: `comparator.sh`.


* Script to validate a positive test case: `pos_case.sh`.


* Script to validate a negative test case: `neg_case.sh`.


* Script for functional testing of positive and negative cases: `func_tests.sh`.
(You can use the "show" parameter to display test results in the terminal).


* Script for automating obtaining data completeness statistics during testing: `collect_coverage.sh`.


* An additional script `code_run.sh` automates the transition to the directory and testing the program using `func_tests.sh`.


* An additional `build_gcov.sh` script automates debug builds to use gcov.
