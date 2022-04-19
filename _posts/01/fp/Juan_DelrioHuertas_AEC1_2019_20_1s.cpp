/*
 * AEC 1 - Práctica 1 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Programa para encriptar o desencriptar mensajes de texto.
 * Está basado en el Método César pero sin realizar una asignación circular
 * de los códigos y sólo asignando un código numérico 
 *
 */

#include <iostream>

using namespace std;

void encriptar(void);
void desencriptar(void);
bool modo_seguro;
/*
 * 
 */
int main(void)
{
    modo_seguro = false;
    cout << "Encriptador por el Método César" << endl;
    int opcion_menu;
    bool salir= false;
	
    // Mostrar menu de opciones -----------------------------------
    // Añado una característica adicional: Modo "Seguro"
    // cuando se activa el algoritmo de encriptación se fortalece un poco
    // ya que dependerá de: 
    //   - clave  
    //   - posición del cáracter en el texto
    //   - longitud del texto
	
    do
    {

        cout << "0) ¿Desea activar modo \"seguro\"? (S/N)" << endl;
        cout << "1) Introducir texto para encriptar." << endl;
        cout << "2) Introducir texto en clave para desencriptar." << endl;
        cout << "3) Salir del programa." << endl << endl; 
        cin >> opcion_menu;
    
        switch (opcion_menu)
        {
            case 0:
                
                if (modo_seguro){
                    modo_seguro = false;
                    cout << "Modo \"seguro\" desactivado. " << endl;                    
                }else{
                    modo_seguro = true;
                    cout << "Modo \"seguro\" activado. " << endl;   
                }
                break;
            case 1: encriptar(); break;
            case 2: desencriptar(); break;
            case 3: 
                cout << "Se cerrará la aplicación.\nHasta la próxima. Gracias por intentarlo." << endl ;                 
                salir = true; break;
            default: cout << "Opción no disponible. Pruebe otra vez" << endl; break;             
        }              
    }while (!salir);  
    
   
    return 0;
}

// Encripta mensaje con un máximo de 25 letras usando una clave numérica entre 0 y 200

void encriptar(void)   
{
   char letra_a_leer = ' ';
   int codigo_de_letra_encriptada = 0;
   string texto_a_encriptar = ""; 
   int longitud_texto;
   int clave;
   bool longitud_incorrecta_texto = true; 
   bool longitud_incorrecta_clave = true; 
   
   int contador_e= 0;
   int contador_a= 0;
   int contador_o= 0;
   int contador_s= 0;
   int contador_r= 0;
   int contador_n= 0;
   int contador_i= 0;
   
   // se aplican los filtros 
   do
   {
        cout << "Introduce la longitud del texto a encriptar (1-25 letras)" << endl;
        cin >> longitud_texto;
        
        longitud_incorrecta_texto = (longitud_texto < 1 || longitud_texto > 25 );
      
        if (cin.fail()){  // filtro para el caso de que se introduzca un valor no numérico
            cout<< "Error. Introduce un valor numérico\n";
            cin.clear();                  
            cin.ignore(2, '\n');
        }else if (longitud_incorrecta_texto == true){ // filtro para el caso de que la longitud no se adecuada
            cout << "Longitud incorrecta." << endl;
        }
        
    }while (longitud_incorrecta_texto);
    
    do
    {   
       cout << "Introduce la clave para encriptar (numero entre 0 a 200): " ;
       cin >> clave;
       longitud_incorrecta_clave = (clave < 0 || clave > 200 || cin.fail());        
       if (cin.fail()){
            cout<< "Error. Introduce un valor numerico\n";
            cin.clear();                  
            cin.ignore(2, '\n');
        }else if (longitud_incorrecta_clave == true){ 
            cout << "Longitud incorrecta clave." << endl;            
        }
cout <<longitud_incorrecta_clave ;
   }while (longitud_incorrecta_clave );
   

   
   for (int i=0;i<longitud_texto;i++)
   {
       cout << "Introduce el caracter numero " << i+1 << " del texto: " ;
       cin >> letra_a_leer;
       
       // Implementación de la fase 2: calcula la frecuencia de aparición 
       // de las 7 letras más habituales en castellano.
       switch (letra_a_leer)
       {
           case 'e': contador_e++;break;
           case 'a': contador_a++;break;
           case 'o': contador_o++;break;
           case 's': contador_s++;break;
           case 'r': contador_r++;break;
           case 'n': contador_n++;break; 
           case 'i': contador_i++;break; 
           case 'E': contador_e++;break;   
           case 'A': contador_a++;break;
           case 'O': contador_o++;break;
           case 'S': contador_s++;break;
           case 'R': contador_r++;break;
           case 'N': contador_n++;break; 
           case 'I': contador_i++;break; 
                    
       }
       
       // se aplica el modo seguro en caso de estar activado
       
       if (modo_seguro){
           codigo_de_letra_encriptada= (int)letra_a_leer + (clave+1) + (i+1) + longitud_texto  ;          
       }else{
        codigo_de_letra_encriptada= (int)letra_a_leer + clave;
       }
       
       cout << "- Codigo para este carácter: " << codigo_de_letra_encriptada << endl;
      
       texto_a_encriptar = texto_a_encriptar + letra_a_leer;
      
      
   }
   cout << "Fin del texto" << endl;
   cout << "Texto completo:" << texto_a_encriptar << endl << endl;
   cout << "ESTADISTICA:" << endl ;
   cout << "La letra E aparece " << contador_e << " veces, un " << (float)contador_e/ longitud_texto * 100 << " %" << endl ;
   cout << "La letra A aparece " << contador_a << " veces, un " << (float)contador_a/ longitud_texto * 100 << " %" << endl ;
   cout << "La letra O aparece " << contador_o << " veces, un " << (float)contador_o/ longitud_texto * 100 << " %" << endl ;
   cout << "La letra S aparece " << contador_s << " veces, un " << (float)contador_s/ longitud_texto * 100 << " %" << endl ;
   cout << "La letra R aparece " << contador_r << " veces, un " << (float)contador_r/ longitud_texto * 100 << " %" << endl ;
   cout << "La letra N aparece " << contador_n << " veces, un " << (float)contador_n/ longitud_texto * 100 << " %" << endl ;
   cout << "La letra I aparece " << contador_i << " veces, un " << (float)contador_i/ longitud_texto * 100 << " %" << endl << endl ;
    
}

// Desencripta mensaje con un máximo de 25 letras usando una clave numérica entre 0 y 200

void desencriptar(void)
{
   int codigo_a_leer = 0;
   char caracter_desencriptado = ' ';
   string texto_desencriptado = ""; 
   int longitud_texto;
   int clave;
   bool longitud_incorrecta_texto = true; 
   bool longitud_incorrecta_clave = true; 
   
   // se aplican los filtros 
   do
   {
        cout << "Introduce la longitud del texto a encriptar (1-25 letras)" << endl;
        cin >> longitud_texto;
        longitud_incorrecta_texto = (longitud_texto < 1 || longitud_texto > 25);
        if (cin.fail()){
            cout<< "Error. Introduce un valor numérico\n";
            cin.clear();                  
            cin.ignore(2, '\n');
        }else if (longitud_incorrecta_texto == true){ 
            cout << "Longitud incorrecta." << endl;
        }
    }while (longitud_incorrecta_texto);
    
    do
    {   
       cout << "¿Cual era la clave para desencriptar? (numero entre 0 a 200): " ;
       cin >> clave;
       longitud_incorrecta_clave = (clave < 0 || clave > 200 || cin.fail());  
       if (cin.fail()){
            cout<< "Error. Introduce un valor numérico\n";
            cin.clear();                  
            cin.ignore(2, '\n');
        }else if (longitud_incorrecta_clave == true){ 
            cout << "Longitud incorrecta clave." << endl;            
        }

   }while (longitud_incorrecta_clave );
     
   for (int i=0;i<longitud_texto;i++)
   {
       cout << "Introduce el codigo del caracter numero " << i+1 << " del texto: " ;
       cin >> codigo_a_leer;
       
       // se aplica el modo seguro en caso de estar activado
       if (modo_seguro){
           caracter_desencriptado= (int)codigo_a_leer - (clave+1) - (i+1) - longitud_texto ;          
       }else{
        caracter_desencriptado= (int)codigo_a_leer - clave;
       }
       
       
       cout << "- Caracter para este código: " << caracter_desencriptado << endl;
       texto_desencriptado = texto_desencriptado + caracter_desencriptado;
       
   }
   cout << "Fin del texto" << endl;
   cout << "Texto completo:" << texto_desencriptado << endl << endl;
    
}