

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

----

Program that check Code's formatting style (indentations, variable naming, brackets, ecc...) saved on xml user-defined rules.

Long description:
Code styler is subdivided in 3 execution sectors (that can be used separately):
* RULER:
    * read the xml file with all rules used by a specified language,
    * then convert it into an xml tree structure,
    * and finally gets all rules.
    * Than ruler have access to these rules and permit to you to modify it (with examples), <br> or you can provide some code snippets to read from.
<br>

* CHECKER:
    * after all rules have been defined by the RULER,
        * this sub-part require the location where you want to apply these rules,
        * if it's a project folder you can avoid some type of files or singular ones.
    * After it has finished, it show to you the result of the operation:
        * it provide some statistic about the project style,
        * the discrepance and other minor information (obviously you can save the result).
<br>

* CLEANER:
    * this is the main program that require RULER and CHECKER results.
    * It uses the result of checker to ask what you want to do:
        * apply the style or change something else (or the absolute and secure nothing).

## Logical subdivision
<table>
    <tr>
        <td style="width:50%">
            <code style="color:red">
                0A
            </code>:
            <code>
                xml --> xml_tree
            </code>
            <br>
            <p style="font-style:italic">
                read xml file and convert it to tree struct
            </p>
        </td>
        <td style="width:50%">
            <code style="color:blue">
                0B
            </code>:
            <code>
                folder --> proj_tree
            </code>
            <br>
            <p style="font-style:italic">
                read all files present in the specified folder and save they on a tree struct
            </p>
        </td>
    </tr>
    <tr>
        <td style="width:50%">
            <code style="color:red">
                1A
            </code>:
            <code>
                xml_tree --> rules_t
            </code>
            <br>
            <p style="font-style:italic">
                get used rules from xml tree and save values on rules struct
            </p>
        </td>
        <td style="width:50%">
            <code style="color:blue">
                1B
            </code>:
            <code>
                proj_tree --> exclude_files
            </code>
            <br>
            <p style="font-style:italic">
                while reading files, accept any user-added exclusion
            </p>
        </td>
    </tr>
</table>


## Dependencies
<code style="color:#66ffff;">g++</code> for compiling <br>
<code style="color:#66ffff;">make</code> for building <br>

---
**FAQ**
======

### Basic usage

Just use it!

### How is it saved?

Save xml for every user-created ruleset (every time the user modify some rules it create the new ruleset).

Example of how rules are saved in xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE CodeStylerStyle>
<!-- Written by CodeStyler program in 09-03-2019 -->
<!-- Rules originally created by Lince99.
    This file define the style of the code inspired by:
        Linux kernel found on github,
        my personal most-liked style,
        qt creator that export style rules into xml file
-->
<language name="example" extensions=".example">
	<!-- comments must follow these style rules for more readability -->
	<comments require="1">
		<!-- describe where does the single comment go -->
		<!-- position rules:
                before = before the name/code
                in = in the same line of the name/code
                after = after the line of name/code
        -->
		<position> top </position>
		<start> "/* " </start>
		<mid> " * " </mid>
		<end> " */" </end>
	</comments>

	<!-- following these rules means that your code is sharable -->
	<!-- text rules:
	        A = all alphabet characters (!n)
            n = accept numbers
            ! = negate the next char rule
            l = lowercase (!U)
            U = uppercase (!l)
            _ = accept only underscore, no spaces allowed. (!s)
            c = accept CamelCase mode (!_) camelcase include starting maiusc
            t = accept tab character. (!s)
            s = accept only space as word-separator, no underscore. (!_)
            m = accept both space and tabs (ts, where s reactivate spaces)
            S = accept special characters like !£$$%&/()=
	-->
	<code require="1">
        <!-- INDENTATION STYLE -->
		<indent require="1">
			<!-- accept: tab (t), space (s), mixed (m) -->
			<type> s </type>
			<count> 4 </count>
            <!-- required space between operators like a = b, spacing = 1 -->
            <spacing> 1 </spacing>
            <!-- position rules:
                    align = require the same char position as upper param line
                    one = accept only one parameter per line
                    none = no rules required
            -->
            <params> "align" </params>
            <vars> "one" </vars>
		</indent>
		<!-- GLOBALS -->
		<global require="1">
            <startChar> "U" </startChar>
            <!-- accept UPPERCASE, no numbers, no CamelCase and no specials -->
            <name> "UA_!S" </name>
		</global>
		<!-- CLASSES/FUNCTIONS -->
        <function require="1">
            <startChar> "l" </startChar>
            <name> "Al_" </name>
            <!-- brackets style -->
            <bracket require="1">
                <!-- accept: yes, no -->
                <required> true </required>
                <!-- where does the open bracket goes -->
                <open>
                    <position> in </position>
                </open>
                <!-- where does the closed bracket goes -->
                <close>
                    <position> after </position>
                </close>
            </bracket>
        </function>
		<!-- VARIABLES -->
        <var require="1">
            <startChar> "l" </startChar>
            <name> "Al_" </name>
        </var>
	</code>
    <!-- FILENAMES -->
    <files require="1">
        <!-- project's directory name -->
        <dir require="1">
            <startChar> "U" </startChar>
            <name> "Anl_" </name>
        </dir>
        <!-- source code's name -->
        <source require="1">
            <startChar> "l" </startChar>
            <name> "Al_" </name>
        </source>
        <!-- libraries directory's name -->
        <libraries require="1">
            <startChar> "l" </startChar>
            <name> "Al_" </name>
        </libraries>
    </files>
    <!-- OTHER RULES -->
    <other require="1">
        <!-- type of copyright/left license used -->
        <copyright require="1">
            <type> "GPL" </type>
        </copyright>
        <!-- encoding types and formatting rules -->
        <encode>
            <type> "UTF-8" </type>
            <newline> "LF" </newline>
        </encode>
    </other>

</language>

```

Inspired by XML used in QT creator:

```xml
<!DOCTYPE QtCreatorCodeStyle>
<!-- Written by QtCreator 4.8.2, 2019-03-09T17:13:56. -->
<qtcreator>
 <data>
  <variable>CodeStyleData</variable>
  <valuemap type="QVariantMap">
   <value type="bool" key="AlignAssignments">false</value>
   <value type="bool" key="AutoSpacesForTabs">false</value>
   <value type="bool" key="BindStarToIdentifier">true</value>
   <value type="bool" key="BindStarToLeftSpecifier">false</value>
   <value type="bool" key="BindStarToRightSpecifier">false</value>
   <value type="bool" key="BindStarToTypeName">false</value>
   <value type="bool" key="ExtraPaddingForConditionsIfConfusingAlign">true</value>
   <value type="bool" key="IndentAccessSpecifiers">false</value>
   <value type="bool" key="IndentBlockBody">true</value>
   <value type="bool" key="IndentBlockBraces">false</value>
   <value type="bool" key="IndentBlocksRelativeToSwitchLabels">false</value>
   <value type="bool" key="IndentClassBraces">false</value>
   <value type="bool" key="IndentControlFlowRelativeToSwitchLabels">true</value>
   <value type="bool" key="IndentDeclarationsRelativeToAccessSpecifiers">true</value>
   <value type="bool" key="IndentEnumBraces">false</value>
   <value type="bool" key="IndentFunctionBody">true</value>
   <value type="bool" key="IndentFunctionBraces">false</value>
   <value type="bool" key="IndentNamespaceBody">false</value>
   <value type="bool" key="IndentNamespaceBraces">false</value>
   <value type="int" key="IndentSize">4</value>
   <value type="bool" key="IndentStatementsRelativeToSwitchLabels">true</value>
   <value type="bool" key="IndentSwitchLabels">false</value>
   <value type="int" key="PaddingMode">2</value>
   <value type="bool" key="ShortGetterName">true</value>
   <value type="bool" key="SpacesForTabs">true</value>
   <value type="int" key="TabSize">4</value>
  </valuemap>
 </data>
 <data>
  <variable>DisplayName</variable>
  <value type="QString">Qt</value>
 </data>
</qtcreator>
```

### Why this program exists?

Programming is an art, surely it use math and other magic stuff that is equal to everyone (shut up quantic things).
But how someone write down programs is subjective, so it's similar to "art".
BUT some people can have some good-looking style, and the others have some things that are simply wrong.
SO this is why this program exist. Lince99.
