#!/usr/bin/env bash

[[ -f ../antlr-4.7.1-complete.jar ]] && rm ../antlr-4.7.1-complete.jar || echo "antlr-4.7.1-complete.jar not found"

cd src/main/java/net/joelcourtney/hadron/parser

[[ -f Hadron.interp ]] && rm Hadron.interp || echo "Hadron.interp not found"
[[ -f Hadron.tokens ]] && rm Hadron.tokens || echo "Hadron.tokens not found"
[[ -f HadronLexer.interp ]] && rm HadronLexer.interp || echo "HadronLexer.interp not found"
[[ -f HadronLexer.tokens ]] && rm HadronLexer.tokens || echo "HadronLexer.tokens not found"
