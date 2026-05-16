# Cardiovascular Expert System
* This was the first project to be assigned in the Introduction to Artificial Intelligence (CS 4346) course offered by Texas State University during the Fall semester of 2021.

**Description**
* This program is an implementation of an expert system designed for "medical professionals" to use in order to diagnose cardiovascular diseases and to recommend a treatment based on the diagnosis. This system is implemented using both the backward and forward chaining algorithms. In order to properly use this software the user must understand the meaning of the abbreviated symptoms, diseases, and treatments. That information is included in the project report.

**Development Environment**
* Acer Aspire E5-575 (x86_64)
* Windows 10
* Code::Blocks 20.03

**Target Environment**
* A server managed by university staff running a Red Hat Enterprise Linux 8.5 instance

**Dependencies**
* GCC 16.1 or newer in order to use the most up to date version of G++
* Git 2.43.0 or newer


# How To Run

* Clone the repo by running the following command:
```
git clone https://github.com/lucasthormann/forward-backward-chaining-demo.git
```
* Build the application by using the following command:
```
g++ -std=c++11 Forward-Backward-Chaining.cpp
```
* Run the assembler output by using the following command:
```
./a.out
```
# Pseudocode

**Backward Chaining & Forward Chaining Simplification**
1. Backward Chaining
- The technique implemented to diagnose a disease was the backward chaining algorithm. This algorithm functions via a few simple data structures. The algorithm's functionalty (in essence) is described via this psuedocode:
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
- The technique implemented to recommend a treatment predicated on the diagnosis was the forward chaining algorithm. This algorithm functions via a few simple data structures as well. The algorithm's functionalty (in essence) is described via this psuedocode:
```
Forward-Chaining
repeat
	for every rule do
		if antecedents match assertions in the rule set and consequents would change the working memory then
			Create triggered rule instance
		end if
	end for
	Pick one triggered rule instance, using conflict resolution strategy if needed, and fire it (throw away other instances) until no change in working memory or no STOP signal
```


