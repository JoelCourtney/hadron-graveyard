grammar Control;

import Base, RValue;

control : valDecl | varDecl;

valDecl : 'val ' ID;
varDecl : 'var ' ID;
