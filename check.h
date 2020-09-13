Symbol *check_general(Symbol*, Symbol*);
Symbol *check_uminus(Symbol*);
Symbol *check_assign(Symbol*, Symbol*);
Symbol *check_id_reference(Symbol *);
Symbol *check_bool(Symbol*, Symbol*);
void check_declaration(Symbol*, AST_Node*);