#define SET_BIT(Byte,n) (Byte|=1<<n)
#define CLR_BIT(Byte,n) (Byte&=~(1<<n))
#define TOG_BIT(Byte,n) (Byte^=(1<<n))
#define GET_BIT(Byte,n) ((Byte>>n)&1)