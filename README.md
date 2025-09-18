# ***Expert Computer System***
* This program was the first project to be assigned in the Introduction to Artificial Intelligence course from the Computer Science Department of Texas State University during the Fall 2021 semester.

**Description**
* This program is an implementation of an expert system designed for medical professionals to use in order to diagnose cardiovascular diseases and to recommend a treatment based on the diagnosis. This software is intended to be used by hospital staff who would input the symptoms of a patient into this expert system. This expert system will diagnose the specific Cardiovascular disease and will recommend the treatment. This system is implemented using both the backward and forward chaining algorithms. In order to properly use this software the user must understand the meaning of the abbreviated symptoms, diseases, and treatments.

* You can clone the repo by running the following command:
```
git clone https://github.com/lucasthormann/forward-backward-chaining-demo.git
```
* You can compile the application using the following command (after changing to the proper directory):
```
g++ -std=c++11 Forward-Backward-Chaining.cpp
```
* You can then execute the produced assembler output using the following command:
```
./a.out
```

**Dependencies For Ease of Execution**
* g++
* Ubuntu 24.04 LTS or later

**Backward Chaining & Forward Chaining Simplification**
1. Backward Chaining
- The technique chosen to diagnose a disease was the Bakcwrad Chaining Algorithm. This algorithm functions via a few simple data structures. The algorithms functionalty in essence is described via this psuedo-code:
```
Backward-Chaining(H)
if H matches an assertion in working memory then
	return true
end if
if there is no rule with a consequent that matches H then
	ASK USER or ASSUME false
end if
for every rule R with a consequent that matches H do
	if for all antecedents A of rule R, we have Backward-Chaining(A) = true then
		return true
	end if
end for
return false
```
2. Forward Chaining
- The technique chosen to diagnose a disease was the Forward Chaining Algorithm. This algorithm functions via a few simple data structures aswell. The algorithms functionalty in essence is described via this psuedo-code:
```
Forward-Chaining
repeat
	for every rule do
		if antecedents match assertions in the rule set and consequents would change
		the working memory then
			Create triggered rule instance
		end if
	end for
	Pick one triggered rule instance, using conflict resolution strategy if needed, and fire it
	(throw away other instances) until no change in working memory, or no STOP signal
```


