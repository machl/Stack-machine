Stack-machine
=============

Zásobníkový stroj

Naprogramujte zásobníkový stroj s těmito instrukcemi:

ADD - scitani

SUB - odcitani, levy operand hloubeji

HALT - konec

LD x - pridani konstanty x na vrchol zasobniku

JMP x - skok o x instrukci dopredu (zaporna cisla dozadu, JMP 1 nedela nic, JMP 0 je nekonecna smycka)

JZ x - odebere vrchol, pokud byl nulovy, skok o x

JP x - odebere vrchol, pokud byl kladny, skok o x

DUP x - prida na vrchol kopii hodnoty z hloubky x ( DUP 0 duplikuje vrchol )

ST x – vrchol zkopiruje do hloubky x, pote vrchol odebere ( ST 0 zahazuje vrchol )

Pracuje se pouze s celymi cisly se znamenkem. Simulator cte program z textoveho souboru, program zacina s prazdnym zasobnikem. Simulator vypisuje obsah zanechany na zasobniku na konci programu (instrukce HALT).