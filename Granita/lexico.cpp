#include "lexico.h"
lexico::lexico(char *file)
{
    linea = 1;
    posc = 0;
    cadena_entrada = "";
    reservados.push_back("bool");
    reservados.push_back("break");
    reservados.push_back("print");
    reservados.push_back("read");
    reservados.push_back("continue");
    reservados.push_back("class");
    reservados.push_back("else");
    reservados.push_back("extends");
    reservados.push_back("false");
    reservados.push_back("for");
    reservados.push_back("if");
    reservados.push_back("int");
    reservados.push_back("new");
    reservados.push_back("null");
    reservados.push_back("return");
    reservados.push_back("not");
    reservados.push_back("true");
    reservados.push_back("void");
    reservados.push_back("while");
    reservados.push_back("rot");

    F = fopen(file,"r");
    if(F != NULL){
        while (feof(F) == 0)
        {
            cadena_entrada += fgetc(F);
        }
    }
    length_cadena = cadena_entrada.length();
    fclose(F);
}

void lexico::ungetc()
{
    posc--;
}

char lexico::NextSymbol(){
    char temp;
    if(posc < length_cadena){
        temp = cadena_entrada.at(posc);
        posc++;
    }
    return temp;
}

Token* lexico::NexToken()
{
    Token *T = new Token();
    while(true){
        CS = NextSymbol();
        if(CS == '\n' || CS == ' ' || CS == '\t')
        {
            if(CS == '\n')
                linea++;
            continue;
        }

        if(CS == -1)
        {
            T->tipo = FINAL;
            return T;
        }
        T->lexema+=CS;
        switch(CS)
        {
        case '}':
            T->tipo = LLAVE_D;
            return T;
        case '{':
            T->tipo = LLAVE_I;
            return T;
        case ']':
            T->tipo = CORCHETE_D;
            return T;
        case '[':
            T->tipo = CORCHETE_I;
            return T;
        case ',':
            T->tipo = COMA;
            return T;
        case ';':
            T->tipo = PUNTO_COMA;
            return T;
        case ')':
            T->tipo = PARENTESIS_D;
            return T;
        case '(':
            T->tipo = PARENTESIS_I;
            return T;
        case '=':
            CS = NextSymbol();
            if(CS=='='){
                T->lexema += CS;
                T->tipo = COMPARACION;
                return T;
            }
            ungetc();
            T->tipo = IGUAL;
            return T;
        case '-':
            T->tipo = GUION;
            return T;
        case '!':
            CS=NextSymbol();
            if(CS=='='){
                T->lexema += CS;
                T->tipo = DISTINTO;
                return T;
            }
            ungetc();
            T->tipo = ADMIRACION;
            return T;
        case '+':
            T->tipo = MAS;
            return T;
        case '*':
            T->tipo = POR;
            return T;
        case '/':
            CS=NextSymbol();
            if(CS == '/')
            {
                //T->lexema+=CS;
                CS=NextSymbol();
                while((CS>=32 && CS <=126) || CS == '\t')
                {
                    //T->lexema+=CS;
                    CS=NextSymbol();
                    if(CS == '\n'){
                        break;
                    }
                }
                T->lexema = "";
                ungetc();
                continue;
            }else if(CS == '*')
            {
                CS=NextSymbol();
                while((CS>=32 && CS <=126) || CS=='\n' || CS=='\t')
                {
                    if(CS=='*')
                    {
                        CS=NextSymbol();
                        if(CS=='/')
                        {
                            break;
                        }
                    }
                    CS=NextSymbol();
                }
                T->lexema = "";
                continue;
            }
            T->tipo = PLECA;
            return T;
        case '<':
            CS = NextSymbol();
            if(CS == '<'){
                T->lexema += CS;
                T->tipo = CORRER_I;
                return T;
            }else if(CS=='='){
                T->lexema += CS;
                T->tipo = MENOR_IGUAL;
                return T;
            }
            ungetc();
            T->tipo = MENOR;
            return T;
        case '>':
            CS = NextSymbol();
            if(CS == '>'){
                T->lexema+=CS;
                T->tipo = CORRER_D;
                return T;
            }else if(CS == '='){
                T->lexema+=CS;
                T->tipo = MAYOR_IGUAL;
                return T;
            }
            ungetc();
            T->tipo = MAYOR;
            return T;
        case '%':
            T->tipo = PORCENTAJE;
            return T;
        case '&':
            CS = NextSymbol();
            if(CS == '&'){
                T->lexema += CS;
                T->tipo = AND;
                return T;
            }else{
                T->tipo = ERROR;
                return T;
            }
        case '|':
            CS = NextSymbol();
            if(CS == '|'){
                T->lexema += CS;
                T->tipo = OR;
                return T;
            }else{
                T->tipo = ERROR;
                return T;
            }
        case '.':
            T->tipo = PUNTO;
            return T;

        //ESTOS SON LOS NUMEROS
        case '0':
            CS = NextSymbol();
            if(CS == 'X' || CS == 'x')
            {
                CS = NextSymbol();
                if((CS >= '0' && CS <= '9')||(CS >='a' && CS <= 'f')||(CS >= 'A' && CS <= 'F'))
                    T->lexema += CS;
                else{
                    T->tipo = ERROR;
                    return T;
                }

                while((CS >= '0' && CS <= '9')||(CS >='a' && CS <= 'f')||(CS >= 'A' && CS <= 'F'))
                {
                    T->lexema+=CS;
                    CS = NextSymbol();
                }
                ungetc();
                T->tipo = INTCONSTANT;
                return T;
            }
            else
            {
                while(CS >= '0' && CS <= '9')
                {
                    T->lexema += CS;
                    CS = NextSymbol();
                }
                ungetc();
                T->tipo = INTCONSTANT;
                return T;
            }

         case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            CS = NextSymbol();
            while(CS >= '0' && CS <= '9')
            {
                T->lexema += CS;
                CS = NextSymbol();
            }
            ungetc();
            T->tipo = INTCONSTANT;
            return T;

         //ESTAS SON LAS CADENAS
         case '"':
            CS = NextSymbol();
            while(CS >= 32 && CS <= 126)
            {
                if(CS == '\\')
                {
                    T->lexema+=CS;
                    CS = NextSymbol();
                    if(CS == '\\' || CS == 't' || CS == 'r' || CS == 'a' || CS == '"' || CS == 'n')
                    {
                        T->lexema+=CS;
                        CS = NextSymbol();

                    }else
                    {
                        T->lexema = "";
                        T->tipo = ERROR;
                        return T;
                    }
                }
                else
                {
                    if(CS == '"'){
                        T->lexema +=CS;
                        T->tipo = CADENA;
                        return T;
                    }
                    T->lexema+=CS;
                    CS = NextSymbol();

                }
            }

         //ESTOS SON LOS CARACTERES
         case '\'':
            CS = NextSymbol();
            if((CS >= 32 && CS <= 126) && (CS != '\\' || CS != '\''))
                T->lexema += CS;
            else if(CS == '\\'){
                T->lexema += CS;
                CS = NextSymbol();
                if(CS == 't' || CS == 'r' || CS == 'a' || CS == '\\' || CS == '"')
                    T->lexema += CS;
                else{
                    T->tipo = ERROR;
                    return T;
                }
            }
            CS = NextSymbol();
            if(CS == '\''){
                T->lexema += CS;
                T->tipo = CARACTER;
                return T;
            }else{
                T->tipo = ERROR;
                return T;
            }

         //AQUI ESTAN LOS ID
         default:
            if((CS >= 'a' && CS <= 'z')||(CS >= 'A' && CS <= 'Z')||CS == '_')
            {
                CS = NextSymbol();
                while((CS >= 'a' && CS <= 'z')||(CS >= 'A' && CS <= 'Z')||CS == '_'||
                      (CS >= '0' && CS <= '9')){
                    T->lexema += CS;
                    CS = NextSymbol();
                }
                ungetc();
                string KW = isreserved(T->lexema);
                if(KW == "true" || KW == "false")
                {
                    T->tipo = BOOLCONSTANT;
                    return T;
                }
                if(KW == "rot")
                {
                    T->tipo = ROT;
                    return T;
                }
                if(KW != "ERROR")
                {
                    if(KW == "bool")
                    T->tipo = KWBOOL;
                    else if(KW == "break")
                    T->tipo = KWBREAK;
                    else if(KW == "print")
                    T->tipo = KWPRINT;
                    else if(KW == "read")
                    T->tipo = KWREAD;
                    else if(KW == "continue")
                    T->tipo = KWCONTINUE;
                    else if(KW == "class")
                    T->tipo = KWCLASS;
                    else if(KW == "else")
                    T->tipo = KWELSE;
                    else if(KW == "extends")
                    T->tipo = KWEXTENDS;
                    else if(KW == "false")
                    T->tipo = KWFALSE;
                    else if(KW == "for")
                    T->tipo = KWFOR;
                    else if(KW == "if")
                    T->tipo = KWIF;
                    else if(KW == "int")
                    T->tipo = KWINT;
                    else if(KW == "new")
                    T->tipo = KWNEW;
                    else if(KW == "null")
                    T->tipo = KWNULL;
                    else if(KW == "return")
                    T->tipo = KWRETURN;
                    else if(KW == "not")
                    T->tipo = KWNOT;
                    else if(KW == "true")
                    T->tipo = KWTRUE;
                    else if(KW == "void")
                    T->tipo = KWVOID;
                    else if(KW == "while")
                    T->tipo = KWWHILE;

                    return T;
                }
                T->tipo = IDENTIFICADOR;
                return T;

            }else{
                T->tipo = ERROR;
                return T;
            }

        }
    }
}
string lexico::isreserved(string id)
{
    list<string>::iterator pos;
    pos = reservados.begin();
    while(pos != reservados.end())
    {
        if(*pos == id)
        {
            return id;
        }
        pos++;
    }
    return "ERROR";
}
