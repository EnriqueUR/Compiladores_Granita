#include "sintactico.h"
#include <qdebug.h>

sintactico::sintactico(char *path)
{
    Lexer = new lexico(path);

    Fallo = false;
    CurrentToken = Lexer->NexToken();
}

void sintactico::MensajeError(string msj, int linea)
{
    cerr<<"Error:"<<msj<<" "<<"linea:"<<linea<<endl;
}

program* sintactico::Program()
{
    list<statementMethodecl*> *list_methodecl = new list<statementMethodecl*>();
    list<statementFieldecl*> *list_fieldecl = new list<statementFieldecl*>();
    if(CurrentToken->tipo == KWCLASS)
    {
        CurrentToken = Lexer->NexToken();
        string class_name = ClassName();
        if(Fallo)
            return NULL;

        if(CurrentToken->tipo == LLAVE_I)
        {
            CurrentToken = Lexer->NexToken();
            Token T[2];
            T[0] = *CurrentToken;
            while(CurrentToken->tipo == KWBOOL || CurrentToken->tipo == KWINT ||
                  CurrentToken->tipo ==KWVOID)
            {
                if(CurrentToken->tipo == KWVOID)
                {
                    CurrentToken = Lexer->NexToken();
                    T[1] = *CurrentToken;
                    CurrentToken = Lexer->NexToken();
                    list_methodecl->push_back(MethodDecl(T));
                    if(Fallo)
                        return NULL;
                    continue;
                }
                CurrentToken = Lexer->NexToken();
                T[1] = *CurrentToken;
                if(CurrentToken->tipo == IDENTIFICADOR){
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo == PARENTESIS_I)
                    {
                        list_methodecl->push_back(MethodDecl(T));
                        if(Fallo)
                            return NULL;
                    }
                    else
                    {
                        list_fieldecl->push_back(FieldDecl(T));
                        if(Fallo)
                            return NULL;
                    }
                }
            }
        }
        if(CurrentToken->tipo != LLAVE_D)
        {
            Fallo = true;
            MensajeError("Se esperaba '}'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        program *prog = new program(class_name,list_methodecl,list_fieldecl);
        return prog;

    }
    else
    {
        Fallo = true;
        MensajeError("Se esperaba class",Lexer->linea);
        return NULL;
    }
}

statementFieldecl* sintactico::FieldDecl(Token T[])
{
    list<string> *list_only_id = new list<string>();
    list<string> *list_id = new list<string>();
    list<exprIntConstant*> *list_constante = new list<exprIntConstant*>();
    statementDeclaration::Type tipo;
    if(T[0].tipo == KWBOOL)
        tipo = statementDeclaration::BOOL;
    else
        tipo = statementDeclaration::INT;
    if(CurrentToken->tipo == CORCHETE_I)
    {
        list_id->push_back(T[1].lexema);
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != INTCONSTANT)
        {
            Fallo = true;
            MensajeError("Se esperaba una constante entera",Lexer->linea);
            return NULL;
        }
        exprIntConstant * entero = new exprIntConstant(atoi(CurrentToken->lexema.c_str()));
        list_constante->push_back(entero);
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != CORCHETE_D)
        {
            Fallo = true;
            MensajeError("Se esperaba ']'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        while(CurrentToken->tipo == COMA)
        {
            CurrentToken = Lexer->NexToken();
            if(CurrentToken->tipo == IDENTIFICADOR)
            {
                string stemp = CurrentToken->lexema;
                CurrentToken = Lexer->NexToken();
                if(CurrentToken->tipo == CORCHETE_I)
                {
                    list_id->push_back(stemp);
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo != INTCONSTANT)
                    {
                        Fallo = true;
                        MensajeError("Se esperaba una constante entera",Lexer->linea);
                        return NULL;
                    }
                    exprIntConstant * entero = new exprIntConstant(atoi(CurrentToken->lexema.c_str()));
                    list_constante->push_back(entero);
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo != CORCHETE_D)
                    {
                        Fallo = true;
                        MensajeError("Se esperaba ']'",Lexer->linea);
                        return NULL;
                    }
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo == COMA)
                        continue;

                }
                else if(CurrentToken->tipo == COMA)
                {
                    list_only_id->push_back(stemp);
                    continue;
                }
            }
        }

        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementFieldecl(tipo,list_only_id,list_id,list_constante);
    }
    else if(CurrentToken->tipo == COMA)
    {
        while(CurrentToken->tipo == COMA)
        {
            CurrentToken = Lexer->NexToken();
            if(CurrentToken->tipo == IDENTIFICADOR)
            {
                string stemp = CurrentToken->lexema;
                CurrentToken = Lexer->NexToken();
                if(CurrentToken->tipo == CORCHETE_I)
                {
                    list_id->push_back(stemp);
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo != INTCONSTANT)
                    {
                        Fallo = true;
                        MensajeError("Se esperaba constante entera",Lexer->linea);
                        return NULL;
                    }
                    exprIntConstant * entero = new exprIntConstant(atoi(CurrentToken->lexema.c_str()));
                    list_constante->push_back(entero);
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo != CORCHETE_D)
                    {
                        Fallo = true;
                        MensajeError("Se esperaba ']'",Lexer->linea);
                        return NULL;
                    }
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo == COMA)
                        continue;

                }
                else if(CurrentToken->tipo == COMA)
                {
                    list_only_id->push_back(stemp);
                    continue;
                }
            }
        }
        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementFieldecl(tipo,list_only_id,list_id,list_constante); //lista de variables
    }
    else if(CurrentToken->tipo == IGUAL)
    {
        CurrentToken = Lexer->NexToken();
        Expression* cons = Constant();
        if(Fallo)
            return NULL;
        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        statementDeclaration::Type tipo;
        if(T[0].tipo == KWBOOL)
            tipo = statementDeclaration::BOOL;
        else
            tipo = statementDeclaration::INT;
        return new statementFieldecl(tipo,T[1].lexema,cons); //variable inicializada
    }else if(CurrentToken->tipo != PUNTO_COMA)
    {
        Fallo = true;
        MensajeError("Se esperaba ';'",Lexer->linea);
        return NULL;
    }
    CurrentToken = Lexer->NexToken();
    list_id->push_back(T[1].lexema);
    return new statementFieldecl(tipo,list_only_id,NULL,NULL); //lista de variables solo con 1 elemento
}

statementMethodecl* sintactico::MethodDecl(Token T[]){
    statementDeclaration::Type type;
    if (T[0].tipo == KWBOOL) {
        type = statementDeclaration::BOOL;
    } else {
        type = statementDeclaration::INT;
    }
    string methodName = T[1].lexema;
    if(CurrentToken->tipo == PARENTESIS_I)
    {
        CurrentToken = Lexer->NexToken();      
        list<statementDeclaration::Type> *paramTypes = new list<statementDeclaration::Type>();
        list<string> *paramNames = new list<string>();
        if(CurrentToken->tipo == KWBOOL || CurrentToken->tipo == KWINT)
        {                  
            if (CurrentToken->tipo == KWBOOL) {
                paramTypes->push_back(statementDeclaration::BOOL);
            } else {
                paramTypes->push_back(statementDeclaration::INT);
            }
            CurrentToken = Lexer->NexToken();
            if(CurrentToken->tipo != IDENTIFICADOR)
            {
                Fallo = true;
                MensajeError("Se esperaba Identificador",Lexer->linea);
                return NULL;
            }
            paramNames->push_back(CurrentToken->lexema);
            CurrentToken = Lexer->NexToken();
            if(CurrentToken->tipo == COMA)
            {
                CurrentToken = Lexer->NexToken();
                while(CurrentToken->tipo == KWBOOL || CurrentToken->tipo == KWINT)
                {
                    if (CurrentToken->tipo == KWBOOL) {
                        paramTypes->push_back(statementDeclaration::BOOL);
                    } else {
                        paramTypes->push_back(statementDeclaration::INT);
                    }
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo != IDENTIFICADOR)
                    {
                        Fallo = true;
                        MensajeError("Se esperaba identificador",Lexer->linea);
                        return NULL;
                    }
                    paramNames->push_back(CurrentToken->lexema);
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo == COMA){
                        CurrentToken = Lexer->NexToken();
                        continue;
                    }else
                        break;
                }
            }
        }
        if(CurrentToken->tipo != PARENTESIS_D)
        {
            Fallo = true;
            MensajeError("Se esperaba ')'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        statementBlock* block;
        block = Block();
        if(Fallo){
            return NULL;
        }
        return new statementMethodecl(type, methodName, paramTypes, paramNames, block);
    }
    else
    {
        Fallo = true;
        MensajeError("Se esperaba ')'",Lexer->linea);
        return NULL;
    }
}

statementBlock* sintactico::Block()
{
    if(CurrentToken->tipo == LLAVE_I)
    {
        list<var_decl*> *var_declarations = new list<var_decl*>();
        list<statement*> *statements = new list<statement*>();
        CurrentToken = Lexer->NexToken();
        while(CurrentToken->tipo == KWBOOL || CurrentToken->tipo == KWINT)
        {
            statementDeclaration::Type type;

            if(CurrentToken->tipo == KWBOOL){
                type = statementDeclaration::BOOL;
            }else{
                type = statementDeclaration::INT;
            }
            var_decl* varDecl = VarDecl();
            varDecl->setType(type);

            var_declarations->push_back(varDecl);
            if(Fallo)
                return NULL;

        }
        while(CurrentToken->tipo == IDENTIFICADOR || CurrentToken->tipo == KWIF || CurrentToken->tipo == KWWHILE
              ||CurrentToken->tipo == KWFOR || CurrentToken->tipo == KWRETURN || CurrentToken->tipo == KWBREAK
              ||CurrentToken->tipo == KWBREAK || CurrentToken->tipo == KWCONTINUE || CurrentToken->tipo == KWPRINT
              ||CurrentToken->tipo == KWREAD || CurrentToken->tipo == LLAVE_I)
        {
            statements->push_back(Statement());//aqui hay problemas
            if(Fallo)
                return NULL;
        }

        if(CurrentToken->tipo != LLAVE_D)
        {
            Fallo = true;
            MensajeError("Se esperaba '}'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementBlock(var_declarations, statements);
    }
    else
    {
        Fallo = true;
        MensajeError("Se esperaba '}'",Lexer->linea);
        return NULL;
    }

}

var_decl* sintactico::VarDecl()
{
    CurrentToken = Lexer->NexToken();
    if(CurrentToken->tipo == IDENTIFICADOR)
    {
        list<string> *ids = new list<string>();
        ids->push_back(CurrentToken->lexema);
        CurrentToken = Lexer->NexToken();
        while(CurrentToken->tipo == COMA)
        {
            CurrentToken = Lexer->NexToken();
            if(CurrentToken->tipo != IDENTIFICADOR)
            {
                Fallo = true;
                MensajeError("Se esperaba Identificador",Lexer->linea);
                return NULL;
            }
            ids->push_back(CurrentToken->lexema);
            CurrentToken = Lexer->NexToken();
        }
        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new var_decl(ids);
    }else
    {
        Fallo = true;
        MensajeError("Se esperaba Identificador",Lexer->linea);
        return NULL;
    }

}

statement* sintactico::Statement()
{
    if(CurrentToken->tipo == KWIF)
    {
        statementBlock *trueBlock, *falseBlock = NULL;
        Expression *condition = NULL;
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo == PARENTESIS_I)
        {
            CurrentToken = Lexer->NexToken();
            condition = A();
            if(Fallo)
                return NULL;

            if(CurrentToken->tipo == PARENTESIS_D)
            {
                CurrentToken = Lexer->NexToken();
                trueBlock = Block();
                if(Fallo)
                    return NULL;
                if(CurrentToken->tipo == KWELSE)
                {
                    CurrentToken = Lexer->NexToken();
                    falseBlock = Block();
                    if(Fallo)
                        return NULL;
                }
            }
            else
            {
                Fallo = true;
                MensajeError("Se esperaba ')'",Lexer->linea);
                return NULL;
            }
        }
        else
        {
            Fallo = true;
            MensajeError("Se esperaba ')'",Lexer->linea);
            return NULL;
        }

        return new statementIf(condition, trueBlock, falseBlock);

    }
    else if(CurrentToken->tipo == KWWHILE)
    {
        Expression *condition;
        statementBlock* block;
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo == PARENTESIS_I)
        {
            CurrentToken = Lexer->NexToken();
            condition = A();
            if(Fallo)
                return NULL;
            if(CurrentToken->tipo == PARENTESIS_D)
            {
                CurrentToken = Lexer->NexToken();
                block = Block();
                if(Fallo)
                    return NULL;
            }
            else
            {
                Fallo = true;
                MensajeError("Se esperaba ')'",Lexer->linea);
                return NULL;
            }
        }
        else
        {
            Fallo = true;
            MensajeError("Se esperaba ')'",Lexer->linea);
            return NULL;
        }
        return new statementWhile(condition, block);
    }
    else if(CurrentToken->tipo == KWFOR)
    {
        list<statementAssign*> *inits = new list<statementAssign*>();
        Expression *condition;
        list<statementAssign*> *increments = new list<statementAssign*>();
        statementBlock* block;
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo == PARENTESIS_I)
        {
            CurrentToken = Lexer->NexToken();
            while (CurrentToken->tipo == IDENTIFICADOR) {
                string id = CurrentToken->lexema;
                CurrentToken = Lexer->NexToken();
                inits->push_back(Assign(id));
                if(Fallo)
                    return NULL;
            }

            if(CurrentToken->tipo == PUNTO_COMA)
            {
                CurrentToken = Lexer->NexToken();
                condition = A();
                if(Fallo)
                    return NULL;
                if(CurrentToken->tipo == PUNTO_COMA)
                {
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo != IDENTIFICADOR)
                    {
                        Fallo = true;
                        MensajeError("Se esperaba Identificador",Lexer->linea);
                        return NULL;
                    }
                    while (CurrentToken->tipo == IDENTIFICADOR) {
                        string id = CurrentToken->lexema;
                        CurrentToken = Lexer->NexToken();
                        increments->push_back(Assign(id));
                        if(Fallo)
                            return NULL;
                    }

                    if(CurrentToken->tipo == PARENTESIS_D)
                    {
                        CurrentToken = Lexer->NexToken();
                        block = Block();
                        if(Fallo)
                            return NULL;
                    }
                    else
                    {
                        Fallo = true;
                        MensajeError("Se esperaba ')'",Lexer->linea);
                        return NULL;
                    }
                }
            }
            else
            {
                Fallo = true;
                return NULL;
            }
        }
        else
        {
            Fallo = true;
            MensajeError("Se esperaba ')'",Lexer->linea);
            return NULL;
        }
        return new statementFor(inits, condition, increments, block);
    }
    else if(CurrentToken->tipo == KWRETURN)
    {
        Expression *returnValue;
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != PUNTO_COMA)
            returnValue = A();

        if(Fallo)
            return NULL;

        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementReturn(returnValue);

    }
    else if(CurrentToken->tipo == KWBREAK)
    {
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementBreak();

    }
    else if(CurrentToken->tipo == KWCONTINUE)
    {
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != PUNTO_COMA)
        {
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementContinue();

    }
    else if(CurrentToken->tipo == LLAVE_I)
    {
        statementBlock *block = Block();
        if(Fallo)
            return NULL;
        return block;
    }
    else if(CurrentToken->tipo == KWPRINT || CurrentToken->tipo == KWREAD)
    {
        statement *printRead = PrintRead();
        if(Fallo)
            return NULL;
        return printRead;
    }
    else if(CurrentToken->tipo == IDENTIFICADOR)
    {
        Token T = *CurrentToken;
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo == PARENTESIS_I)
        {
            statement *mc = MethodCallStatement(T);
            if(Fallo)
                return NULL;
            if(CurrentToken->tipo != PUNTO_COMA)
            {
                Fallo = true;
                MensajeError("Se esperaba ';'",Lexer->linea);
                return NULL;
            }
            CurrentToken = Lexer->NexToken();
            return mc;
        }
        else if(CurrentToken->tipo == CORCHETE_I || CurrentToken->tipo == IGUAL)
        {
            statement *assign = Assign(T.lexema);
            if(Fallo)
                return NULL;
            if(CurrentToken->tipo != PUNTO_COMA)
            {
                Fallo = true;
                MensajeError("Se esperaba ';'",Lexer->linea);
                return NULL;
            }
            CurrentToken = Lexer->NexToken();
            return assign;
        }
    }
}

statement* sintactico::PrintRead()
{
    statement * result = NULL;
    if(CurrentToken->tipo == KWPRINT)
    {
        CurrentToken = Lexer->NexToken();
        list<exprArgument*> *args = new list<exprArgument*>();
        args->push_back(Argument());
        while(CurrentToken->tipo == COMA){
            CurrentToken = Lexer->NexToken();
            if(Fallo)
                return NULL;
            args->push_back(Argument());
        }
        if(CurrentToken->tipo != PUNTO_COMA){
            Fallo = true;
            MensajeError("Se esperaba ';'",Lexer->linea);
            return NULL;
        }
        result = new statementPrint(args);
    }
    else if(CurrentToken->tipo == KWREAD)
    {
        CurrentToken = Lexer->NexToken();
        string id ;
        Expression * expr = NULL;
        list<exprLvalue*> *lvalues = new list<exprLvalue*>();
        if(CurrentToken->tipo == IDENTIFICADOR)
        {
            id = CurrentToken->lexema;
            CurrentToken = Lexer->NexToken();
            if(CurrentToken->tipo == CORCHETE_I)
            {
                CurrentToken = Lexer->NexToken();
                expr = A();
                if(CurrentToken->tipo != CORCHETE_D)
                {
                    Fallo = true;
                    MensajeError("Se esperaba ']'",Lexer->linea);
                    return NULL;
                }
                CurrentToken = Lexer->NexToken();
                lvalues->push_back(new exprLvalue(id,expr));

                while(CurrentToken->tipo == COMA)
                {
                    CurrentToken = Lexer->NexToken();
                    if(CurrentToken->tipo == IDENTIFICADOR)
                    {
                        id = CurrentToken->lexema;
                        CurrentToken = Lexer->NexToken();
                        if(CurrentToken->tipo == CORCHETE_I)
                        {
                            CurrentToken = Lexer->NexToken();
                            expr = A();
                            if(CurrentToken->tipo != CORCHETE_D)
                            {
                                Fallo = true;
                                MensajeError("Se esperaba ']'",Lexer->linea);
                                return NULL;
                            }
                            CurrentToken = Lexer->NexToken();
                            lvalues->push_back(new exprLvalue(id,expr));
                        }
                        else
                        {
                            lvalues->push_back(new exprLvalue(id));
                        }
                    }
                }
            }
            else
            {
                lvalues->push_back(new exprLvalue(id));
            }

        }
        result = new statementRead(lvalues);
    }
    if(CurrentToken->tipo != PUNTO_COMA)
    {
        Fallo = true;
        MensajeError("Se esperaba ';'",Lexer->linea);
        return NULL;
    }
    CurrentToken = Lexer->NexToken();
    return result;
}

statementAssign* sintactico::Assign(string id)
{
    Expression *value = NULL;
    exprLvalue* lValue;
    if(Fallo)
        return NULL;
    if(CurrentToken->tipo == IGUAL)
    {
        lValue = new exprLvalue(id);
        CurrentToken = Lexer->NexToken();
        value = A();
        if(Fallo)
            return NULL;
    } else if (CurrentToken->tipo == CORCHETE_I){
        CurrentToken = Lexer->NexToken();
        Expression * index = A();
        if (CurrentToken->tipo == CORCHETE_D) {
            CurrentToken = Lexer->NexToken();
            lValue = new exprLvalue(id, index);
            if (CurrentToken->tipo == IGUAL) {
                CurrentToken = Lexer->NexToken();
                value = A();
                if(Fallo)
                    return NULL;
            }

        } else {//error
        }
    }
    return new statementAssign(lValue, value);
}

statementMethodCall* sintactico::MethodCallStatement(Token T)
{
    if(CurrentToken->tipo == PARENTESIS_I)
    {
        list<Expression*> *params = new list<Expression*>();
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != PARENTESIS_D)
            params->push_back(A());
        while(CurrentToken->tipo == COMA)
        {
            CurrentToken = Lexer->NexToken();
            params->push_back(A());
            if(Fallo)
                return NULL;
        }
        if(CurrentToken->tipo != PARENTESIS_D)
        {
            Fallo = true;
            MensajeError("Se esperaba ')'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new statementMethodCall(T.lexema, params);
    }
    return NULL;
}

Expression* sintactico::MethodCallExpression(Token T)
{
    if(CurrentToken->tipo == PARENTESIS_I)
    {
        list<Expression*> *params = new list<Expression*>();
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo != PARENTESIS_D)
            params->push_back(A());
        while(CurrentToken->tipo == COMA)
        {
            CurrentToken = Lexer->NexToken();
            params->push_back(A());
            if(Fallo)
                return NULL;
        }
        if(CurrentToken->tipo != PARENTESIS_D)
        {
            Fallo = true;
            MensajeError("Se esperaba ')'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return new exprMethodCall(T.lexema, params);
    }
    return NULL;
}

string sintactico::MethodName()
{
    if(CurrentToken->tipo == IDENTIFICADOR)
    {
        CurrentToken = Lexer->NexToken();
        return NULL;
    } else {
        string methodName = CurrentToken->lexema;
        CurrentToken = Lexer->NexToken();
        return methodName;
    }
}

string sintactico::ClassName()
{
    if(CurrentToken->tipo != IDENTIFICADOR)
    {
        Fallo = true;
        MensajeError("Se esperaba Identificador",Lexer->linea);
        return NULL;
    } else {
        string name = CurrentToken->lexema;
        CurrentToken = Lexer->NexToken();
        return name;
    }
}

exprArgument* sintactico::Argument()
{
    if(CurrentToken->tipo == CADENA)
    {
        string cadena = CurrentToken->lexema;
        CurrentToken = Lexer->NexToken();
        return new exprArgument(cadena);
    }
    Expression* value = A();
    if(Fallo)
        return NULL;
    return new exprArgument(value);
}

exprLvalue* sintactico::Lvalue()
{
    if(CurrentToken->tipo == CORCHETE_I)
    {
        CurrentToken = Lexer->NexToken();
        Expression* expr = A();
        if(Fallo)
           return NULL;
        if(CurrentToken->tipo != CORCHETE_D)
        {
            Fallo = true;
            MensajeError("Se esperaba ']'",Lexer->linea);
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        exprLvalue *value = new exprLvalue();
        value->setExpr(expr);
        return value;
    } else if (CurrentToken->tipo == IDENTIFICADOR) {
        exprLvalue* lValue = new exprLvalue(CurrentToken->lexema);
        CurrentToken = Lexer->NexToken();
        return lValue;
    }
}

Expression* sintactico::Constant()
{
    Expression* expression =  NULL;
    if (CurrentToken->tipo == INTCONSTANT) {
        expression = new exprIntConstant(atoi(CurrentToken->lexema.c_str()));
    } else if (CurrentToken->tipo == CARACTER) {
        char c = CurrentToken->lexema.at(0);
        expression = new exprIntConstant(c);
    } else if (CurrentToken->tipo == BOOLCONSTANT) {
        if (CurrentToken->lexema == "false") {
            expression = new exprBoolConstant(false);
        } else {
            expression = new exprBoolConstant(true);
        }
    } else {
        Fallo = true;
        MensajeError("Se esperaba una constante",Lexer->linea);
        return NULL;
    }
    CurrentToken = Lexer->NexToken();
    return expression;
}


//aqui esta la precedencia de operadores

Expression* sintactico::A()
{
    Expression* izq = B();
    while(CurrentToken->tipo == OR)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = B();
        izq = new ExprOr(izq,der);
    }
    return izq;
}

Expression* sintactico::Ap()
{
    if(CurrentToken->tipo == OR)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = B();
        Expression* der = Ap();
        if(der != NULL)
            return new ExprOr(izq, der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::B(){
    Expression *izq = C();
    while(CurrentToken->tipo == AND)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = C();
        izq = new exprAnd(izq,der);
    }
    return izq;
}

Expression* sintactico::Bp()
{
    if(CurrentToken->tipo == AND)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = C();
        Expression* der = Bp();
        if(izq != NULL)
            return new exprAnd(izq, der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::C()
{
    Expression* izq = D();
    while(CurrentToken->tipo == DISTINTO)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = D();
        izq = new exprDistin(izq,der);
    }
    while(CurrentToken->tipo == COMPARACION)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = D();
        izq = new exprEqual(izq,der);
    }

    return izq;
}

Expression* sintactico::Cp()
{
    if(CurrentToken->tipo == COMPARACION)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = D();
        Expression* der = Cp();
        if(der != NULL)
            return new exprEqual(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == DISTINTO)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = D();
        Expression* der = Cp();
        if(der != NULL)
            return new exprDistin(izq,der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::D()
{
    Expression* izq = E();
    while(CurrentToken->tipo == MENOR)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = E();
        izq = new exprLessThan(izq,der);
    }
    while(CurrentToken->tipo == MENOR_IGUAL)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = E();
        izq = new exprLessAndEqual(izq,der);
    }
    while(CurrentToken->tipo == MAYOR)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = E();
        izq = new exprGreaterThan(izq,der);
    }
    while(CurrentToken->tipo == MAYOR_IGUAL)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = E();
        izq = new exprGreaterAndEqual(izq,der);
    }
    return izq;
}

Expression* sintactico::Dp()
{
    if(CurrentToken->tipo == MENOR)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = E();
        Expression* der = Dp();
        if(der != NULL)
            return new exprLessThan(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == MENOR_IGUAL)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = E();
        Expression* der = Dp();
        if(der != NULL)
            return new exprLessAndEqual(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == MAYOR)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = E();
        Expression* der = Dp();
        if(der != NULL)
            return new exprGreaterThan(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == MAYOR_IGUAL)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = E();
        Expression* der = Dp();
        if(der != NULL)
            return new exprGreaterAndEqual(izq,der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::E()
{
    Expression* izq = F();
    while(CurrentToken->tipo == CORRER_D)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = F();
        izq = new exprShiftRight(izq,der);
    }
    while(CurrentToken->tipo == CORRER_I)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = F();
        izq = new exprShiftLeft(izq,der);
    }
    while(CurrentToken->tipo == ROT)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = F();
        izq = new exprRot(izq,der);
    }
    return izq;
}

Expression* sintactico::Ep()
{
    if(CurrentToken->tipo == CORRER_D)
    {
        CurrentToken = Lexer->NexToken();
        Expression *izq = F();
        Expression *der = Ep();
        if(der != NULL)
            return new exprShiftRight(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == CORRER_I)
    {
        CurrentToken = Lexer->NexToken();
        Expression *izq = F();
        Expression *der = Ep();
        if(der != NULL)
            return new exprShiftLeft(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == ROT)
    {
        CurrentToken = Lexer->NexToken();
        Expression *izq = F();
        Expression *der = Ep();
        if(der != NULL)
            return new exprRot(izq,der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::F()
{
    Expression* izq = G();
    while(CurrentToken->tipo == PORCENTAJE)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = G();
        izq = new exprMode(izq,der);
    }
    return izq;
}

Expression* sintactico::Fp()
{
    if(CurrentToken->tipo == PORCENTAJE)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = G();
        Expression* der = Fp();
        if(der != NULL)
            return new exprMode(izq,der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::G()
{
    Expression* izq = H();
    while(CurrentToken->tipo == MAS)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = H();
        izq = new exprAdd(izq,der);
    }
    while(CurrentToken->tipo == GUION)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = H();
        izq = new exprSub(izq,der);
    }
    return izq;
}

Expression* sintactico::Gp()
{
    if(CurrentToken->tipo == MAS)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = H();
        Expression* der = Gp();
        if(der != NULL)
            return new exprAdd(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == GUION)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = H();
        Expression* der = Gp();
        if(der != NULL)
            return new exprSub(izq,der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::H()
{
    Expression* izq = I();
    while(CurrentToken->tipo == POR)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = I();
        izq = new exprMult(izq,der);
    }
    while(CurrentToken->tipo == PLECA)
    {
        CurrentToken = Lexer->NexToken();
        Expression *der = I();
        izq = new exprDiv(izq,der);
    }
    return izq;
}

Expression* sintactico::Hp()
{
    if(CurrentToken->tipo == POR)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = I();
        Expression* der = Hp();
        if(der != NULL)
            return new exprMult(izq,der);
        return izq;
    }
    else if(CurrentToken->tipo == PLECA)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = I();
        Expression* der = Hp();
        if(der != NULL)
            return new exprDiv(izq,der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::I()
{
    Expression* expr = J();
    if(CurrentToken->tipo == ADMIRACION)
    {
        CurrentToken = Lexer->NexToken();
        return new exprDeni(expr);
    }
    return expr;
}

Expression* sintactico::Ip()
{
    if(CurrentToken->tipo == ADMIRACION)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = J();
        Expression* der = Ip();
        if(der != NULL)
            return new exprDeni(der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::J()
{
    if(CurrentToken->tipo == GUION)
    {
        CurrentToken = Lexer->NexToken();
        Expression *expr;
        expr = new exprNegative(A());
    }
    else if(CurrentToken->tipo == PARENTESIS_I)
    {
        CurrentToken = Lexer->NexToken();
        Expression* expression = A();
        if(CurrentToken->tipo != PARENTESIS_D)
        {
            Fallo = true;
            return NULL;
        }
        CurrentToken = Lexer->NexToken();
        return expression;
    }
    else if(CurrentToken->tipo == IDENTIFICADOR)
    {
        Expression* expression = NULL;
        Token T = *CurrentToken;
        string str = T.lexema;
        CurrentToken = Lexer->NexToken();
        if(CurrentToken->tipo == PARENTESIS_I)
        {
            expression = MethodCallExpression(T);
            if(Fallo)
                return NULL;
        }
        else if(CurrentToken->tipo == CORCHETE_I)
        {
            exprLvalue *lv = Lvalue();
            lv->setId(str);
            expression = lv;
            if(Fallo)
                return NULL;
        }
        else
        {
            expression = new exprLvalue(str);
        }

        if(Fallo)
            return NULL;

        return expression;

    }
    else if(CurrentToken->tipo == INTCONSTANT || CurrentToken->tipo == CADENA ||
       CurrentToken->tipo == BOOLCONSTANT)
    {
        Expression* expression = Constant();
        if(Fallo)
            return NULL;
        return expression;
    }
    else
    {
        Fallo = true;
        MensajeError("Se esperaba una constante o identificador",Lexer->linea);
        return NULL;
    }
}

Expression* sintactico::Jp()
{
    if(CurrentToken->tipo == GUION)
    {
        CurrentToken = Lexer->NexToken();
        Expression* izq = K();
        Expression* der = Jp();
        if(der != NULL)
            return new exprNegative(der);
        return izq;
    }
    return NULL;
}

Expression* sintactico::K()
{

}
