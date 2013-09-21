#ifndef SINTACTICO_H
#define SINTACTICO_H
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "token.h"
#include "lexico.h"

#include "program.h"
#include "statementif.h"
#include "statementfor.h"
#include "statementread.h"
#include "statementprint.h"
#include "statementbreak.h"
#include "statementwhile.h"
#include "statementreturn.h"
#include "statementcontinue.h"
#include "statementfieldecl.h"
#include "statementmethodecl.h"
#include "statementmethodcall.h"

#include "expror.h"
#include "exprand.h"
#include "exprmethodcall.h"
#include "exprboolconstant.h"
#include "exprequal.h"
#include "exprlessthan.h"
#include "exprlessandequal.h"
#include "exprgreaterthan.h"
#include "exprgreaterandequal.h"
#include "exprdistin.h"
#include "exprshiftleft.h"
#include "exprshiftright.h"
#include "exprrot.h"
#include "exprmode.h"
#include "expradd.h"
#include "exprsub.h"
#include "exprmult.h"
#include "exprdiv.h"
#include "exprdeni.h"
#include "exprnegative.h"

using namespace std;

class sintactico
{
public:
    sintactico(char *path);
    bool Fallo;
    lexico *Lexer;

    Token *CurrentToken;
    program *Program();
    string ClassName();
    statementFieldecl *FieldDecl(Token T[]);
    statementMethodecl *MethodDecl(Token T[]);
    statementMethodCall *MethodCallStatement(Token T);
    string MethodName();
    void Type();
    Expression* Constant();
    void BoolConstant();
    statementBlock* Block();
    var_decl* VarDecl();
    statement* Statement();
    statementAssign* Assign(string id);

    exprLvalue* Lvalue();
    exprArgument* Argument();
    Expression* MethodCallExpression(Token T);
    void AritOp();
    void RelOp();
    void EqOp();
    void CondOp();

    //extras :P
    statement * PrintRead();
    void MensajeError(string msj,int linea);

    //nuevos metodos
    Expression* A();
    Expression* Ap();
    Expression* B();
    Expression* Bp();
    Expression* C();
    Expression* Cp();
    Expression* D();
    Expression* Dp();
    Expression* E();
    Expression* Ep();
    Expression* F();
    Expression* Fp();
    Expression* G();
    Expression* Gp();
    Expression* H();
    Expression* Hp();
    Expression* I();
    Expression* Ip();
    Expression* J();
    Expression* Jp();
    Expression* K();


};

#endif // SINTACTICO_H
