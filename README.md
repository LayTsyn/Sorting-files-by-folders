[![License](https://img.shields.io/github/license/LayTsyn/Sorting-files-by-folders)](https://github.com/LayTsyn/Sorting-files-by-folders/blob/main/LICENSE)

# Sorting-files-by-folders
Based on the filesystem C++17 standard library, a small program has been implemented that will sort your files by the specified file path. At the moment there are two modes: by file extension and by last modified date.
> :pushpin: The tool is not perfect but don't worry, it doesn't break anything

## Table of contents

1. [System requirements](#1-system-requirements)
2. [Installation](#2-installation)
3. [How to use](#3-how-to-use)
4. [Tests](#4-tests)

## 1. System requirements

in development

## 2. Installation

in develop
<!--
To use this tool, type in a terminal:
```bash
# Clone the repo
git clone https://github.com/LayTsyn/Sorting-files-by-folders.git
# Go to folder
cd Sorting-files-by-folders
# Install dependencies
pip install -r requirements.txt
# launch tool
sf [-options]
```

It will run the tool, waiting for your input.
-->

## 3. How to use

Navigate to the directory where you want to sort the files into folders. For example:
```bash
>>cd Desktop\test\
```
Let's check that there are files in this folder.
```bash
>>dir
```
<details>
<summary>My files in this folder:</summary>
<sub> 1614947983_1233319.png  <br/> </sub>
<sub> 4fd7bf44ab7d8857d0f68de504e6001e.jpg  <br/> </sub>
<sub> b67602c6cb.png  <br/> </sub>
<sub> c477753744a3b053869c3ffc12ce5dfd.jpg  <br/> </sub>
<sub> Config.lnk  <br/> </sub>
<sub> d0a727ea25fabce0815b40a135294e31.jpg  <br/> </sub>
<sub> Document Microsoft Word — copy— copy — copy — copy — copy.docx  <br/> </sub>
<sub> Document Microsoft Word — copy— copy— copy (2) — copy.docx  <br/> </sub>
<sub> Document Microsoft Word — copy— copy— copy (2).docx  <br/> </sub>
<sub> Document Microsoft Word — copy— copy— copy.docx  <br/> </sub>
<sub> Document Microsoft Word — copy— copy— copy— copy (2).docx  <br/> </sub>
<sub> Document Microsoft Word — copy— copy— copy— copy (3).docx  <br/> </sub>
<sub> Document Microsoft Word — copy— copy— copy— copy.docx  <br/> </sub>
<sub> Document Microsoft Word.docx  <br/> </sub>
<sub> eko.png  <br/> </sub>
<sub> Hd-scenery-image.jpg  <br/> </sub>
<sub> image.png  <br/> </sub>
<sub> List Microsoft Excel — copy— copy (2) — copy— copy.xlsx  <br/> </sub>
<sub> List Microsoft Excel — copy— copy— copy (2) — copy.xlsx  <br/> </sub>
<sub> List Microsoft Excel — copy— copy— copy (3).xlsx  <br/> </sub>
<sub> List Microsoft Excel — copy— copy— copy.xlsx  <br/> </sub>
<sub> List Microsoft Excel — copy— copy— copy— copy(2).xlsx  <br/> </sub>
<sub> List Microsoft Excel — copy— copy— copy— copy— copy.xlsx  <br/> </sub>
<sub> List Microsoft Excel.xlsx  <br/> </sub>
<sub> List Microsoft Excel— copy— copy— copy— copy(2).xlsx  <br/> </sub>
<sub> New text file — copy (2) — copy — copy.txt  <br/> </sub>
<sub> New text file — copy— copy (2) — copy.txt  <br/> </sub>
<sub> New text file — copy— copy(2).txt  <br/> </sub>
<sub> New text file — copy— copy.txt  <br/> </sub>
<sub> New text file — copy— copy(3).txt  <br/> </sub>
<sub> New text file — copy— copy— copy (2).txt  <br/> </sub>
<sub> New text file — copy— copy— copy.txt  <br/> </sub>
<sub> New text file — copy— copy— copy— copy.txt  <br/> </sub>
<sub> New text file.txt  <br/> </sub>
<sub> Noname.bmp  <br/> </sub>
<sub> Nonefile  <br/> </sub>
<sub> Nonefile — copy  <br/> </sub>
<sub> Nonefile — copy— copy  <br/> </sub>
<sub> Nonefile — copy— copy— copy  <br/> </sub>
<sub> png-clipart-4k-resolution-high-definition-television-high-definition-video-men-s-camera-action-electronics-microphone.png  <br/> </sub>
<sub> Visual Studio Code.lnk  <br/> </sub>
</details>

Then you change the directory to the cloned `sf.exe` file. And run the program with the flag and path to the files you want to sort. The flag I will choose `-e` (`--extenstion` - sort files by extension) and point the path to the folder test on the Desktop (if the `sf.exe` program is in the same directory as the files you want to sort, you can leave the second parameter blank)

```bash
>>sf -e [your_path]\Desktop\test\
```
If everything was done correctly, the sorting is done. Let's make sure of that. Let's go back to our file folder.
```bash
>>cd [your_path]\Desktop\test\
>>dir
```
<details>
<summary>My result after sort:</summary>
<sub> .bmp  <br/> </sub>
<sub> .docx  <br/> </sub>
<sub> .jpg  <br/> </sub>
<sub> .lnk  <br/> </sub>
<sub> .png  <br/> </sub>
<sub> .txt  <br/> </sub>
<sub> .xlsx  <br/> </sub>
<sub> Nonefile  <br/> </sub>
<sub> Nonefile — copy  <br/> </sub>
<sub> Nonefile — copy— copy  <br/> </sub>
<sub> Nonefile — copy— copy— copy  <br/> </sub>
</details>

 Files named "None" have not been moved across folders because they have no extension, as you can see. And we ran sorting by file extension.
 
## 4. Tests

in development




<!-- - **-** **`NameDescribtion`** - TextDescribtion -->
