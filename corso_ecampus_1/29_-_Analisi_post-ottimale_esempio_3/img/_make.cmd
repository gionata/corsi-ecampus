@echo off
:Loop
IF "%1"=="" GOTO Continue
latex "%~d1%~p1%~n1"
dvips -E -o "%~d1%~p1%~n1.eps" "%~d1%~p1%~n1.dvi"
del "%~d1%~p1%~n1.aux" "%~d1%~p1%~n1.log" "%~d1%~p1%~n1.dvi"
SHIFT
GOTO Loop
:Continue