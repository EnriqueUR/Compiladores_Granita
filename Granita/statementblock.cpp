#include "statementblock.h"

statementBlock::statementBlock()
{
}

statementBlock::statementBlock(list<var_decl*> *vars, list<statement*> *sentences) {
    this->vars = vars;
    this->sentences = sentences;
}
void statementBlock::print()
{
    cout<<"{"<<endl;
    list<var_decl*>::iterator itv;
    itv = vars->begin();
    while(itv != vars->end())
    {
        var_decl *v = *itv;
        v->print();
        cout<<endl;
        itv++;
    }
    list<statement*>::iterator its;
    its = sentences->begin();
    while(its != sentences->end())
    {
        statement *s = *its;
        s->print();
        cout<<endl;
        its++;
    }
    cout<<"}"<<endl;
}
