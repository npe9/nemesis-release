/* $XConsortium: coKeynames.h,v 1.1 94/03/28 21:22:29 dpw Exp $ */
/*
 * This file is derived from "atKeynames.h"
 * Written by Holger Veit (veit@du9ds3.uni-duisburg.de)
 * Modified to provide a translation table between codrv's scancodes, and
 * the keycodes defined in "atKeynames.h" (David Dawes)
 * (modifed by Matt Holgate)
 *
 * The e0keysymtab is derived from /usr/src/linux/drivers/char/keyboard.c
 * written by Johan Myreen
 * (Matt Holgate)
 */

#include <keysym.h>

#define CTRL(_c) ((_c) - '@')

const int keysymtab[512] = {
    XK_VoidSymbol, /* START OF NORMAL MAP: keycode XK_VoidSymbol */
    XK_Escape,  
    XK_1,          
    XK_2,         
    XK_3,        
    XK_4,       
    XK_5,      
    XK_6,     
    XK_7,    
    XK_8,   
    XK_9,  
    XK_0,
    XK_minus,       
    XK_equal,      
    /* XK_Backspace */ XK_Delete, 
    XK_Tab,      
    XK_q,       
    XK_w,      
    XK_e,     
    XK_r,    
    XK_t,   
    XK_y,  
    XK_u, 
    XK_i,
    XK_o,           
    XK_p,          
    XK_bracketleft, 
    XK_bracketright,  
    XK_Return,     
    XK_Control_L, 
    XK_a,           
    XK_s,          
    XK_d,         
    XK_f,        
    XK_g,       
    XK_h,      
    XK_j,     
    XK_k,    
    XK_l,   
    XK_semicolon,  
    XK_quoteright,
    XK_grave,
    XK_Shift_L,
    XK_numbersign,  
    XK_z,       
    XK_x,    
    XK_c,           
    XK_v,          
    XK_b,         
    XK_n,        
    XK_m,       
    XK_comma,  
    XK_period,
    XK_slash,
    XK_Shift_R,     
    XK_VoidSymbol,     
    XK_Alt_L,   
    XK_space,       
    XK_Caps_Lock, 
    XK_F1,
    XK_F2,
    XK_F3,
    XK_F4,
    XK_F5,
    XK_F6,
    XK_F7,
    XK_F8,
    XK_F9,
    XK_F10,
    XK_VoidSymbol, 
    XK_Scroll_Lock,
    XK_VoidSymbol,
    XK_Insert,      
    XK_Delete,      
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_Left,        
    XK_Home,        
    XK_End,         
    XK_VoidSymbol,
    XK_Up,          
    XK_Down,        
    XK_Prior,       
    XK_End,         
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_backslash,       
    XK_F11,
    XK_F12,
    XK_KP_4,        
    XK_KP_1,        
    XK_VoidSymbol,
    XK_KP_Divide,   
    XK_KP_8,        
    XK_KP_5,        
    XK_KP_2,        
    XK_KP_0,
    XK_KP_Multiply, 
    XK_KP_9,        
    XK_KP_6,        
    XK_KP_3,        
    XK_KP_Decimal,  
    XK_KP_Subtract, 
    XK_KP_Add,      
    XK_VoidSymbol,
    XK_KP_Enter,    
    XK_VoidSymbol,
    XK_Escape,      
    XK_VoidSymbol,
    XK_F1,          
    XK_F2,          
    XK_F3,          
    XK_F4,          
    XK_F5,          
    XK_F6,          
    XK_F7,          
    XK_F8,          
    XK_F9,          
    XK_F10,
    XK_F11,         
    XK_F12,         
    XK_Print,       
    XK_Scroll_Lock, 
    XK_Print,       
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol, /* START OF SHIFT MAP: keycode XK_VoidSymbol */
    XK_Escape,  
    XK_exclam,          
    XK_quotedbl,         
    XK_sterling,        
    XK_dollar,       
    XK_percent,      
    XK_asciicircum,      
    XK_ampersand,     
    XK_asterisk,    
    XK_parenleft,  
    XK_parenright, 
    XK_underscore,       
    XK_plus,      
    /* XK_Backspace */ XK_Delete, 
    XK_Tab,      
    XK_Q,       
    XK_W,      
    XK_E,     
    XK_R,    
    XK_T,   
    XK_Y,  
    XK_U, 
    XK_I,
    XK_O,           
    XK_P,          
    XK_braceleft, 
    XK_braceright,  
    XK_Return,     
    XK_Control_L, 
    XK_A,           
    XK_S,          
    XK_D,         
    XK_F,        
    XK_G,       
    XK_H,      
    XK_J,     
    XK_K,    
    XK_L,   
    XK_colon,  
    XK_at,
    XK_bar,
    XK_Shift_L,
    XK_asciitilde,  
    XK_Z,       
    XK_X,    
    XK_C,           
    XK_V,          
    XK_B,         
    XK_N,        
    XK_M,       
    XK_less,  
    XK_greater,
    XK_question,
    XK_Shift_R,     
    XK_VoidSymbol,     
    XK_Alt_L,   
    XK_space,       
    XK_Caps_Lock, 
    XK_F1,
    XK_F2,
    XK_F3,
    XK_F4,
    XK_F5,
    XK_F6,
    XK_F7,
    XK_F8,
    XK_F9,
    XK_F10,
    XK_VoidSymbol, 
    XK_Scroll_Lock,
    XK_VoidSymbol,
    XK_Insert,      
    XK_Delete,      
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_Left,        
    XK_Home,        
    XK_End,         
    XK_VoidSymbol,
    XK_Up,          
    XK_Down,        
    XK_Prior,       
    XK_End,         
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_bar,       
    XK_F11,
    XK_F12,        
    XK_KP_4,        
    XK_KP_1,        
    XK_VoidSymbol,
    XK_KP_Divide,   
    XK_KP_8,        
    XK_KP_5,        
    XK_KP_2,        
    XK_KP_0,
    XK_KP_Multiply, 
    XK_KP_9,        
    XK_KP_6,        
    XK_KP_3,        
    XK_KP_Decimal,  
    XK_KP_Subtract, 
    XK_KP_Add,      
    XK_VoidSymbol,
    XK_KP_Enter,    
    XK_VoidSymbol,
    XK_Escape,      
    XK_VoidSymbol,
    XK_F1,          
    XK_F2,          
    XK_F3,          
    XK_F4,          
    XK_F5,          
    XK_F6,          
    XK_F7,          
    XK_F8,          
    XK_F9,          
    XK_F10,
    XK_F11,         
    XK_F12,         
    XK_Print,       
    XK_Scroll_Lock, 
    XK_Print,       
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol, /* START OF CTRL MAP: keycode XK_VoidSymbol */
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    /* XK_Backspace */ XK_Delete, 
    XK_VoidSymbol,
    CTRL('Q'),       
    XK_VoidSymbol,
    CTRL('E'),
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    CTRL('P'),          
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_Control_L,
    CTRL('A'),           
    CTRL('S'),          
    CTRL('D'),         
    CTRL('F'),        
    CTRL('G'),       
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    CTRL('L'),   
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_Shift_L,
    XK_VoidSymbol,
    CTRL('Z'),       
    XK_VoidSymbol,
    CTRL('C'),           
    XK_VoidSymbol,
    CTRL('B'),         
    CTRL('N'),        
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_Shift_R,
    XK_VoidSymbol,     
    XK_Alt_L,
    XK_VoidSymbol,
    XK_Caps_Lock,
    XK_F1,
    XK_F2,
    XK_F3,
    XK_F4,
    XK_F5,
    XK_F6,
    XK_F7,
    XK_F8,
    XK_F9,
    XK_F10,
    XK_VoidSymbol, 
    XK_Scroll_Lock,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_F11,
    XK_F12,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol, /* START OF CTRL-SHFT MAP: keycode XK_VoidSymbol */
    XK_Escape,  
    XK_1,          
    XK_2,         
    XK_3,        
    XK_4,       
    XK_5,      
    XK_6,     
    XK_7,    
    XK_8,   
    XK_9,  
    XK_0,
    XK_minus,       
    XK_equal,      
    /* XK_Backspace */ XK_Delete, 
    XK_Tab,      
    XK_Q,       
    XK_W,      
    XK_E,     
    XK_R,    
    XK_T,   
    XK_Y,  
    XK_U, 
    XK_I,
    XK_O,           
    XK_P,          
    XK_braceleft, 
    XK_braceright,  
    XK_Return,     
    XK_Control_L, 
    XK_A,           
    XK_S,          
    XK_D,         
    XK_F,        
    XK_G,       
    XK_H,      
    XK_J,     
    XK_K,    
    XK_L,   
    XK_semicolon,  
    XK_quoteright,
    XK_grave,
    XK_Shift_L,
    XK_numbersign,  
    XK_Z,       
    XK_X,    
    XK_C,           
    XK_V,          
    XK_B,         
    XK_N,        
    XK_M,       
    XK_comma,  
    XK_period,
    XK_slash,
    XK_Shift_R,     
    XK_VoidSymbol,     
    XK_Alt_L,   
    XK_space,       
    XK_Caps_Lock, 
    XK_F1,
    XK_F2,
    XK_F3,
    XK_F4,
    XK_F5,
    XK_F6,
    XK_F7,
    XK_F8,
    XK_F9,
    XK_F10,
    XK_VoidSymbol, 
    XK_Scroll_Lock,
    XK_VoidSymbol,
    XK_Insert,      
    XK_Delete,      
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_Left,        
    XK_Home,        
    XK_End,         
    XK_VoidSymbol,
    XK_Up,          
    XK_Down,        
    XK_Prior,       
    XK_End,         
    XK_VoidSymbol, 
    XK_VoidSymbol,
    XK_backslash,       
    XK_F11,
    XK_F12,        
    XK_KP_4,        
    XK_KP_1,        
    XK_VoidSymbol,
    XK_KP_Divide,   
    XK_KP_8,        
    XK_KP_5,        
    XK_KP_2,        
    XK_KP_0,
    XK_KP_Multiply, 
    XK_KP_9,        
    XK_KP_6,        
    XK_KP_3,        
    XK_KP_Decimal,  
    XK_KP_Subtract, 
    XK_KP_Add,      
    XK_VoidSymbol,
    XK_KP_Enter,    
    XK_VoidSymbol,
    XK_Escape,      
    XK_VoidSymbol,
    XK_F1,          
    XK_F2,          
    XK_F3,          
    XK_F4,          
    XK_F5,          
    XK_F6,          
    XK_F7,          
    XK_F8,          
    XK_F9,          
    XK_F10,
    XK_F11,         
    XK_F12,         
    XK_Print,       
    XK_Scroll_Lock, 
    XK_Print,       
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol,
    XK_VoidSymbol
};

/* escaped scancode table */

const int e0keysymtab[128] = {
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x00-0x07 */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x08-0x0f */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x10-0x17 */
  0, 0, 0, 0, XK_KP_Enter, XK_Control_R, 0, 0,        /* 0x18-0x1f */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x20-0x27 */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x28-0x2f */
  0, 0, 0, 0, 0, XK_KP_Divide, 0, XK_Print,           /* 0x30-0x37 */
  XK_Alt_R, 0, 0, 0, 0, 0, 0, 0,                      /* 0x38-0x3f */
  0, 0, 0, 0, 0, 0, 0, XK_Home,                       /* 0x40-0x47 */
  XK_Up, XK_Prior, 0, XK_Left, 0, XK_Right, 0, XK_End,/* 0x48-0x4f */
  XK_Down, XK_Next, XK_Insert, XK_Delete, 0, 0, 0, 0, /* 0x50-0x57 */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x58-0x5f */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x60-0x67 */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x68-0x6f */
  0, 0, 0, 0, 0, 0, 0, 0,                             /* 0x70-0x77 */
  0, 0, 0, 0, 0, 0, 0, 0                              /* 0x78-0x7f */
};
