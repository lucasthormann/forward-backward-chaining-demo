***Expert Computer System***
This submission contains the first project of the Introduction to Artificial Intelligence class from the Computer Science Departmenet of Texas State University.

Description
This program is an intelligent computer expert system designed for a hospital to use in order to diagnose Cardiovascular (Heart) diseases and to recommend the treatment based on the diagnosis. This software is intended to be used by hospital staff by feeding the symptoms of a patient to this expert system. This expert system will diagnose the specific Cardiovascular disease and will recommend the treatment. This system is implemented using both backward and forward chaining algorithms. In order to properly use this software the user must understand the meaning of the abbreviated symptoms, diseases, and treatments. The user can unerstand these abbreviates by reading the project report. This expert system was implemented using two primary algorithms:
Backward Chaining
Forward Chaining

Building on Windows/MAC/Linux
In order to properly run and use this program, you must install the .cpp file, download and read the project report, and download and read the readme file. This software is capable of running on any computational device capable of compiling and executing C++ files.
Once you have properly installed the .cpp file, you should then open it in an IDE capable of compiling and executing C++ files. Once the file is properly opened in a functional IDE, use the tools provided by the IDE to build and run the single C++ file.

Dependencies
Install the latest version of an IDE capable of compiling and executing C++ files

Building
We've used CodeBlocks IDE for running and debugging, so the execution could be done using the graphical interface of the IDE.

Backward Chaining & Forward Chaining Simplification
1. Backward Chaining
The technique chosen to diagnose a disease was the Bakcwrad Chaining Algorithm. This algorithm functions via a few simple data structures. The algorithms functionalty in essence is described via this psuedo-code:

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

2. Forward Chaining
The technique chosen to diagnose a disease was the Forward Chaining Algorithm. This algorithm functions via a few simple data structures aswell. The algorithms functionalty in essence is described via this psuedo-code:

Forward-Chaining
repeat
	for every rule do
		if antecedents match assertions in the rule set and consequents would change
		the working memory then
			Create triggered rule instance
		end if
	end for
	Pick one triggered rule instance, using conflict resolution strategy if needed, and fire it
	(throw away other instances)
until no change in working memory, or no STOP signal
