#define PRINT_PASSED_INFO() \
    printf("%s%s%s","[",__func__,"] passed.\n")

#define PRINT_ALL_PASSED_INFO(object)\
    printf("%s","===Tests of ["#object"] all passed.===")

#define PRINT_VAR_ADDR(var)\
    printf("%08x\n",&(var))