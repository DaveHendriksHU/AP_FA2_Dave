Warehouse Project Fa 2:
    Warehouse project 2023

ABOUT:
    Dit project gaat over het maken van een warehouse met meerdere shelves die 4 pallets hebben.
    De bedoeling is om eigen functies te maken en hier testen voor te schrijven om te bewijzen dat ze werken.
    Daarnaast word er in de main een kleine demo gegeven dat de functies ook echt naar behoren werken.

AUTEUR:
    Naam: Dave Hendriks
    Klas: V1A
    StudentenNummer : 1836238

INSTALL:
    1. Als er nog geen C++ is geinstalleerd is dat de eerste stap.
    2. clone de repository naar uw computer en pull dan alle bestanden van de main branch
    3. Open dan de Warehouse folder in uw code editor
    4. Er zijn 2 builds mogelijk in dit project.
    4.1 Een van de builds is voor de main, Die een kleine demo geeft over wat het programme zou moeten doen.
    Die Build ziet er als volgt uit in de makefile.
        - Configuration : [Unset]
        - Build target : [All]
        - Launch target : [Main]
        - Makefile : [MakeFile]
        - Make : Dit hangt af van waar je Mingw32-make.exej hebt geïnstalleerd op de computer
        - Build Log : [Unset]
    4.2 De tweede build. Zal de test's runnen om aan te tonen dat functies naar behoren werken.
        - Configuration : [Unset]
        - Build target : [All]
        - Launch target : [testfa2]
        - Makefile : [MakeFile]
        - Make : Dit hangt af van waar je Mingw32-make.exej hebt geïnstalleerd op de computer
        - Build Log : [Unset]
    5. Nu zou het mogelijk moeten zijn om een van de twee builds runnen.

MANUEL / Help:
    1. Bij het runnen van de main build zult u veel print statments te zien krijgen
    2. De print statments zijn voorall daar om te demonstreren dat functies naar behoren werken.  

MANIFEST:
    README.MD
    MakeFile
    warehouse_uml.png
    main.cpp
    folder:src
        employee.cpp
        pallet.cpp
        shelf.cpp
        warehouse.cpp
        folder:include
            employee.hpp
            Icontainer.hpp
            pallet.hpp
            shelf.hpp
            warehouse.hpp
    folder:test
        testfa2.cpp
        testWarehouse.cpp
        folder:include
            catch.hpp
BUGS:
    1. Geen Bugs op dit moment bekend.
    2.Mocht u een bug tegen komen kunt u het melden door een mailtje te sturen naar dave.hendriks@student.hu.nl

Sources Used:
    - Chatgpt.
    - Stackoverflow.