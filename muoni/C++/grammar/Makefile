grammar:
	java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:${CLASSPATH}" org.antlr.v4.Tool -Dlanguage=Cpp -no-listener -visitor -o antlr4-runtime Muon.g4
	mv antlr4-runtime/*.h ../inc/Grammar
	mv antlr4-runtime/*.cpp ../src/Grammar
	sed -i '' -e 's/public:/&%Data* cache = nullptr;/g' ../inc/Grammar/MuonParser.h
	sed -i '' -e 's/#include "antlr4-runtime.h"/&%#include "Data\/Data.h"/g' ../inc/Grammar/MuonParser.h
	tr '%' '\n' < ../inc/Grammar/MuonParser.h | sponge ../inc/Grammar/MuonParser.h
	touch ../CMakeLists.txt
	git add ../inc/Grammar/*
	git add ../src/Grammar/*

clean:
	rm antlr4-runtime/* ../inc/Grammar/* ../src/Grammar/*
