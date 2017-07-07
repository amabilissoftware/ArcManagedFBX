![arcmanagedfbx](http://i.imgur.com/br4KwNr.png)

====
## Amabilis Changes
I've made quite a few changes in support of exporting. No doubt they could be better since I am definitely NOT a C++ programmer.

Btw, these are pretty helpful to know: (here showing how little I know about these things)

//C#, value type passed by value : (int a) — C++ / CLI : the same : (int a)
//C#, value type passed by ref : (ref int a) — C++ / CLI : the same : (int %a)
//C#, reference type passed by value : (string a) — C++ / CLI : (string ^a)
//C#, reference type passed by ref : (ref string a) — C++ / CLI : (string ^%a).

====
## Description
A managed common-language runtime wrapper for the Autodesk FBX SDK 2015. Enables developers writing in C# or any other .NET supported language to work with the FBX SDK without having to use any other aspect of the CLR's platform invocation services.

## Features
* Import and save scenes
* Modify cameras, attributes, nodes and more.
* Comprehensive wrapper of most of the features documented by the FBX SDK.
* To be useable with the [Arcane Dreams MonoGame fork](https://github.com/arcanedreams/MonoGame) that is actively being worked on.

## Requirements
* [Visual Studio 2012 with Update 4](http://www.microsoft.com/en-gb/download/details.aspx?id=39305)
* [Autodesk FBX SDK 2015](http://usa.autodesk.com/adsk/servlet/pc/item?siteID=123112&id=10775847)

## Purpose
* To be used in conjunction with MonoGame for importing the FBX file asset type and retrieving more indepth information about files imported through the API.

## Shoutout
https://github.com/returnString/ManagedFBX



