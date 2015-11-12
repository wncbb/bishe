
#ifndef DECLARATION_SPECIFIERS_H
#define DECLARATION_SPECIFIERS_H

struct storage_class_specifier_infor{
    /*
    none ---------------------------- 0(default, depend on the scope)
    TYPEDEF(typedef) ---------------- 1
    EXTERN(extern) ------------------ 2
    STATIC(static) ------------------ 3
    THREAD_LOCAL(thread_local) ------ 4
    AUTO(auto) ---------------------- 5
    REGISTER(register) -------------- 6
    */    


    int value;
};


struct type_specifier_infor{
    /*
    void -----------------------------  1
    bool -----------------------------  2
   
    signed   char --------------------  3
    unsigned char --------------------  4
  
    singed   short int ---------------  5
    unsigned short int ---------------  6
    signed   int ---------------------  7
    unsigned int ---------------------  8
    signed   long int ----------------  9
    unsigned long int ---------------- 10
    signed   long long int ----------- 11
    unsigned long long int ----------- 12

    float ---------------------------- 13
    double --------------------------- 14
    long double ---------------------- 15
 
    complex -------------------------- 16
    imaginary ------------------------ 17
    atomic_type_specifier ------------ 18
    struct_or_union_specifier -------- 19
    
    enum_specifier ------------------- 20

    struct_or_union_specifier -------- 21
    */
    int value;
};


struct type_qualifier_infor
{
    /*
    none ------------------- 0x0000_0000
    those below could coexist
    const ------------------ 0x0000_0001
    restrict --------------- 0x0000_0010
    volatile --------------- 0x0000_0100
    atomic ----------------- 0x0000_1000
    */
    int value;
};

struct function_specifier_infor
{
    /*
    none ----------------- 0(default)
    those below can coexist
    INLINE(inline) ------- 0x0000_0001
    NORETURN(noreturn) --- 0x0000_0010
    */
    int value;
};

struct alignment_specifier_infor{
    /*
    not used yet
    alignment_specifier:
    : ALIGNAS (type name)
    | ALIGNAS (constant expression)
    */
    

};


struct declaration_specifiers_infor{
    struct storage_class_specifier_infor scs_1;
    struct type_specifier_infor ts_2; 
    struct type_qualifier_infor tq_3;
    struct function_specifier_infor fs_4;
    struct alignment_specifier_infor as_5;
};

#endif

int deal_declaration_specifiers(int node_index);







