# CppLogger
### C++ powered logging tool

---

# Objectives
<br>
To handle all the logging requirements of a tool, including its header, footer, messages & gracious exit.
To log all the activities to a log file and to (optionally) print the same to the user (STDOUT).

---

# Recommended Operations
<br>
1. Gathering tool name, current version & identifier/tagline from the user
2. Initializing log file(s)
3. Formatting header & footer
4. Color coding based on severities
5. Mapping codes to log messages
6. Formatting the log messages
7. Logging the messages to a log file
8. Printing the messages to STDOUT
9. Exiting the tool

---

# Usage
<br>
Edit the include/tool.hpp header before using the tool. 
Recommended convention is that,

- Module names begin with MOD_

- Returncodes end with the name of the severity i.e., _PASS, _FAIL, _INFO

- PASS and INFO severities is to use positive integers

- FAIL severity is to use negative integers
<br>

To instantiate a new Logger object, `Logger test ("test.log")` or `Logger test ("test.log", true)`

To add a header line, `test.Header ("Test")` or `test.Header ()`

To add a footer line, `test.Footer ()`

To add a log message, `test.Log (PASS, MOD_INIT, INIT_PASS, false, opt)`
- Note that instantiating logger object with verbose flag will override the user flag and print all the messages to STDOUT.
- Similarly user flag set to true will override verbose flag and print the particular log message to STDOUT.

---