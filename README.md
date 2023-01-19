# WordCount Utility
 
WordCount counts the number of lines, words, and bytes for the specified file and outputs this information to the output stream.  The program supports the following options:


**-l, --lines**    output only the number of lines

**-c, --bytes**    output the file size in bytes

**-w, --words**    output the number of words

**-m, --chars**     output the number of letters



The file name and options are passed through command line arguments in the following format:


_**WordCount.exe [OPTION] filename [filename,.....]***_


Output format (without specified options):
  lines words bytes filename
  
  
### Examples of program startup:
_WordCount.exe filename1_
 
_WordCount.exe filename1 filename2_

_WordCount.exe --words --lines filename1_

_WordCount.exe -l -c filename1_
 
_WordCount.exe -lwc filename1 filename2_

_WordCount.exe  filename1 filename2 -lw --bytes_ 
