<div style="margin: auto; text-align: center; font-weight: bold;">
 <h1 style="display: inline; font-weight: bold">Code Styler</h1>
 <br>
 <br>
</div>

General stuff: <br>
![Language](https://img.shields.io/github/languages/top/Lince99/Code_styler.svg)
![GitHub](https://img.shields.io/github/license/Lince99/Code_styler.svg?logoColor=orange) <br>
Git info: <br>
![Branch](https://img.shields.io/github/last-commit/Lince99/Code_styler.svg)
![GitHub issues](https://img.shields.io/github/issues/Lince99/Code_styler.svg?logoColor=red)
![GitHub closed issues](https://img.shields.io/github/issues-closed/Lince99/Code_styler.svg?logoColor=blue) <br>
Repo stats: <br>
![GitHub repo size in bytes](https://img.shields.io/github/repo-size/Lince99/Code_styler.svg)
![Downloads](https://img.shields.io/github/downloads/Lince99/Code_styler/total.svg) <br>

* * *

Program that check Code's formatting style (indentations, variable naming, brackets, ecc...) saved on xml user-defined rules.

Long description:
Code styler is subdivided in 3 execution sectors (that can be used separately):

-   RULER:
    -   read the xml file with all rules used by a specified language,
    -   then convert it into an xml tree structure,
    -   and finally gets all rules.
    -   Than ruler have access to these rules and permit to you to modify it (with examples), <br> or you can provide some code snippets to read from.


-   CHECKER:
    -   after all rules have been defined by the RULER,
        -   this sub-part require the location where you want to apply these rules,
        -   if it's a project folder you can avoid some type of files or singular ones.
    -   After it has finished, it show to you the result of the operation:
        -   it provide some statistic about the project style,
        -   the discrepance and other minor information (obviously you can save the result).


-   CLEANER:
    -   this is the main program that require RULER and CHECKER results.
    -   It uses the result of checker to ask what you want to do:
        -   apply the style or change something else (or the absolute and secure nothing).

## Logical subdivision

Every step code will be used in commits, pulls, ... messages.<br>
Steps with bigger font and bold code means that they are run always, without user interaction after the launch command.

-   XML RULES

    -   <code style="color:red; font-weight:bold; font-size: 17px;">0A</code> :
        <code>rules.xml --> xml_tree</code>
        read xml file and convert it to tree struct

    -   <code style="color:red; font-weight:bold; font-size: 17px;">1A</code> :
        <code>xml_tree --> rules_t</code>
        get rules from xml tree and save values on rules struct

    -   <code style="color:red;">2A</code> :
        <code>rules_t --> modify_rules()</code>
        the user can modify all rules saved at 1A

    -   <code style="color:red;">3A</code> :
        <code>rules_t --> xml_tree</code>
        the user can also save the modified rules into another xml file

    -   <code style="color:red;;">4A</code> :
        <code>xml_tree --> new_rules.xml</code>
        if user used 3A, the program save a tmp file or the user can permanently save it

-   PROJECT DIRECTORY

    -   <code style="color:blue; font-weight:bold; font-size: 17px;">0B</code> :
        <code>folder --> proj_tree</code>
        read all files present in the specified folder and save they on a tree struct

    -   <code style="color:blue;">1B</code> :
        <code>proj_tree --> exclude_files</code>
        while reading files, accept any user-added exclusion

-   APPLY RULES TO PROJECT TREE

    -   <code style="color:magenta; font-weight:bold; font-size: 17px;">0C</code> :
        <code>rules_t --> proj_tree</code>
        apply saved rules to every file in the project tree and produce rules_results

    -   <code style="color:magenta; font-weight:bold; font-size: 17px;">1C</code> :
        <code>rules_results --> save_stats()</code>
        for every file save statistics about violation of rules

-   SAVE ERRORS AND FIX IT

    -   <code style="color:green; font-weight:bold; font-size: 17px;">0D</code> :
        <code>rules_results --> style_fix</code>
        for every file that have errors modify that files

    -   <code style="color:green;">1D</code> :
        <code>style_fix --> interactive_fix()</code>
        for every file propose to user if he/she want to fix or not style errors

    -   <code style="color:green; font-weight:bold; font-size: 17px;">2D</code> :
        <code>style_fix --> folder</code>
        apply chosen style fixes

## Dependencies

<code style="color:#66ffff;">g++</code> for compiling <br>
<code style="color:#66ffff;">make</code> for building <br>

* * *

# **FAQ**

### Basic usage

Just use it!

### How is it saved?

Save xml for every user-created ruleset (every time the user modify some rules it create the new ruleset).

Example of how rules are saved in xml:<br>
Usable data types:

-   position:
    -   before = before the name/code
    -   in = in the same line of the name/code
    -   after = after the line of name/code
    -   align = require the same char position as upper parameter line
    -   one = accept only one parameter per line
    -   none = no rules required
-   string:
    -   accept any type of string and require " before and after in the tag value
-   char:
    -   accept any type of character and require " before and after in the tag value
-   int:
    -   accept any type of integer value (no commas or dots are allowed)
-   boolean:
    -   true or false (uppercase and lowercase),
    -   1 and 0
-   require:
    -   1: rule generate error if not respected
    -   0: rule generate only a warning message if the program is run in an interactive way

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE CodeStylerStyle>
<!-- Written by CodeStyler VERSION_NUMBER at DATE(mm-hh_DD-MM-YYYY) -->
<language name="example" extensions=".example">
	<!-- comments must follow these style rules for more readability -->
	<comments require="1">
		<!-- describe where does the single comment go -->
		<!-- position rules:
                before = before the name/code
                in = in the same line of the name/code
                after = after the line of name/code
        -->
		<position type="position"> "top" </position>
		<start type="string"> "/* " </start>
		<mid type="string"> " * " </mid>
		<end type="string"> " */" </end>
	</comments>

	<!-- following these rules means that your code is sharable -->
	<!-- text rules:
	        A = all alphabet characters (!n)
            n = accept numbers
            ! = negate the next char rule
            l = lowercase (!U)
            U = uppercase (!l)
            _ = accept only underscore, no spaces allowed. (!s)
            c = accept CamelCase mode (!_), camelcase include maiusc at start
            t = accept tab character. (!s)
            s = accept only space as word-separator, no underscore. (!_)
            m = accept both space and tabs (ts, where s reactivate spaces)
            S = accept special characters like !£$$%&/()=
	-->
	<code require="1">
        <!-- INDENTATION STYLE -->
		<indent require="1">
			<!-- accept: tab (t), space (s), mixed (m) -->
			<startChar type="char"> "s" </startChar>
			<count type="int"> 4 </count>
            <!-- required space between operators like a = b, spacing = 1 -->
            <spacing type="int"> 1 </spacing>
            <!-- position rules:
                    align = require the same char position as upper param line
                    one = accept only one parameter per line
                    none = no rules required
            -->
            <params type="string"> "align" </params>
            <vars type="position"> "one" </vars>
		</indent>
		<!-- GLOBALS -->
		<global require="1">
            <startChar type="char"> "U" </startChar>
            <!-- accept UPPERCASE, no numbers, no CamelCase and no specials -->
            <name type="string"> "UA_!S" </name>
		</global>
		<!-- CLASSES/FUNCTIONS -->
        <function require="1">
            <startChar type="char"> "l" </startChar>
            <name type="string"> "Al_" </name>
            <!-- brackets style -->
            <bracket require="1">
                <!-- accept: yes, no -->
                <required type="boolean"> true </required>
                <!-- where does the open bracket goes -->
                <open>
                    <position type="position"> "in" </position>
                </open>
                <!-- where does the closed bracket goes -->
                <close>
                    <position type="position"> "after" </position>
                </close>
            </bracket>
        </function>
		<!-- VARIABLES -->
        <var require="1">
            <startChar type="char"> "l" </startChar>
            <name type="string"> "Al_" </name>
        </var>
	</code>
    <!-- FILENAMES -->
    <files require="1">
        <!-- project's directory name -->
        <dir require="1">
            <startChar type="char"> "U" </startChar>
            <name type="string"> "Anl_" </name>
        </dir>
        <!-- source code's name -->
        <source require="1">
            <startChar type="char"> "l" </startChar>
            <name type="string"> "Al_" </name>
        </source>
        <!-- libraries directory's name -->
        <libraries require="1">
            <startChar type="char"> "l" </startChar>
            <name type="string"> "Al_" </name>
        </libraries>
    </files>
    <!-- OTHER RULES -->
    <other require="1">
        <!-- type of copyright/left license used -->
        <copyright require="1">
            <name type="string"> "GPL" </name>
        </copyright>
        <!-- encoding types and formatting rules -->
        <encode>
            <name type="string"> "UTF-8" </name>
            <newline type="string"> "LF" </newline>
        </encode>
    </other>
</language>
```

### Why this program exists?

Programming is an art, surely it use math and other magic stuff that is equal to everyone (shut up quantic things).
But how someone write down programs is subjective, so it's similar to "art".
BUT some people can have some good-looking style, and the others have some things that are simply wrong.
SO this is why this program exist. Lince99.
