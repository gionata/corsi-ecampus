@echo off
SET USAGE=Usage: dvi2eps.cmd file_to_process
IF "%1" == "" (
 ECHO %USAGE%
 EXIT
)
echo Converting DVI to EPS
echo dvips -E -o "%~d1%~p1%~n1.eps" "%~dpnx1"
dvips -E -o "%~d1%~p1%~n1.eps" "%~dpnx1"
