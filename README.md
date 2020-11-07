# GDPR-Radar
GDPR Radar checks the document either it consists all the necessary information according to the GDPR regulation.

## Requirements

Terminal in MacOS.

## Build and run the project

Creat a folder and clone the repository:

```git clone https://github.com/pshagwel/GDPR-Radar.git .```

Build the project:

```make```

Run the programm with one argument: file name of a tested document with the extension "txt".

```./gdpr "document.txt"```

## Instructions

The list of phrases is located in ./srcs/phrases.txt.
Each phrase should be divided by "\n" and should not contain any spaces.
The tested document should have an extension "txt".
The result of the GDPR checker will show up in the file "conclusion.txt".

## Demo
Demo compiled program is located in the ./app
Rebuild demo with command: 

```make app```