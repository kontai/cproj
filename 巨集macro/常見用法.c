//1.防止一个头文件被重复包含

#ifndef COMDEF_H
#define COMDEF_H

//头文件内容 …
#endif

//2.重新定义一些类型，防止由于各种平台和编译器的不同，而产生的类型字节数差异，方便移植。

typedef  unsigned long int  uint32;      	/* Unsigned 32 bit value */

//3.得到指定地址上的一个字节或字

#define  MEM_B( x )  ( *( (byte *) (x) ) )
#define  MEM_W( x )  ( *( (word *) (x) ) )
//4.求最大值和最小值

#define  MAX( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y )  ( ((x) < (y)) ? (x) : (y) )

//5.得到一个field在结构体(struct)中的偏移量

#define FPOS( type, field )   ( (dword) &(( type *) 0)-> field )

//6.得到一个结构体中field所占用的字节数

#define FSIZ( type, field ) sizeof( ((type *) 0)->field )

//7.按照LSB格式把两个字节转化为一个word

#define  FLIPW( ray ) ( (((word) (ray)[0]) * 256) + (ray)[1] )

//8.按照LSB格式把一个word转化为两个字节

#define  FLOPW( ray, val ) \
(ray)[0] = ((val) / 256); \
(ray)[1] = ((val) & 0xFF)

//9.得到一个变量的地址（word宽度）

#define  B_PTR( var )  ( (byte *) (void *) &(var) )
#define  W_PTR( var )  ( (word *) (void *) &(var) )

//10.得到一个字的高位和低位字节

#define  WORD_LO(xxx)  ((byte) ((word)(var) & 255))
#define  WORD_HI(xxx)  ((byte) ((word)(var) >> 8))

//11.返回一个比X大的最接近的8的倍数

#define RND8( x )       ((((x) + 7) / 8 ) * 8 )

//12.将一个字母转换为大写

#define  UPCASE( ch ) ( ((ch) >= ’a' && (ch) <= ’z') ? ((ch) - 0×20) : (ch) )

//13.判断字符是不是10进值的数字

#define  DECCHK( ch ) ((ch) >= ’0′ && (ch) <= ’9′)

//14.判断字符是不是16进值的数字

#define  HEXCHK( ch ) \
(((ch) >= ’0′ && (ch) <= ’9′) || \
((ch) >= ’A' && (ch) <= ’F') || \
((ch) >= ’a' && (ch) <= ’f') )

//15.防止溢出的一个方法

#define  INC_SAT( val )  (val = ((val)+1 > (val)) ? (val)+1 : (val))

//16.返回数组元素的个数

#define  ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )

//17.对于IO空间映射在存储空间的结构，输入输出处理

#define inp(port)         (*((volatile byte *) (port)))
#define inpw(port)        (*((volatile word *) (port)))
#define inpdw(port)       (*((volatile dword *)(port)))

#define outp(port, val)   (*((volatile byte *) (port)) = ((byte) (val)))
#define outpw(port, val)  (*((volatile word *) (port)) = ((word) (val)))
#define outpdw(port, val) (*((volatile dword *) (port)) = ((dword) (val)))