#!/bin/bash

yacc -d final.yacc
flex final.flex
gcc *.c