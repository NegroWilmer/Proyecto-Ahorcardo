


#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>

using namespace std;

int intentos_incorrectos = 0;

int number_letters() {
    int n_letras;
    cout<<endl;
    cout << "¿Cuántas letras tiene tu palabra?" << endl << endl;
    cin >> n_letras;
    if (n_letras <= 0 || n_letras > 50) {
            cout << "El número debe estar entre 1 y 50 o ingreso algo que no es un número. Intenta de nuevo." << endl << endl;
    
        exit(0);
    }
    cout << endl;
    

    cout << "!Tu palabra es de " << n_letras << " letras¡" << endl << endl;
    return n_letras;
}

string abecedario = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

int intentos = 6;

bool es_letra_valida(char letra) {
    letra = toupper(letra);
    for (char l : abecedario) {
        if (l == letra) {
            return true;
        }
    }
    return false;
}

int run(){
    int n_letras = number_letters();

    vector<char> palabra_original;

    cout << "¡Por favor! Escribe tu palabra" << endl << endl;

    string palabra;
cin >> palabra;

if (palabra.length() != n_letras) {
    cout << "Error: La longitud de la palabra no coincide con el número de letras indicado o tiene espacios" << endl;
    exit(0);
}

for (char b : palabra) {
    

    b = toupper(b);

    if (!es_letra_valida(b)) {
        cout << "Error: La palabra contiene al menos un carácter no válido." << endl;
        exit(0);
    }

    palabra_original.push_back(b);
}
    cout << "!Perfecto! Ya tenemos tu palabra" << endl << endl;
    
    
    cin.ignore();

   string pista;
   cout << "Escribe una pista para la palabra (puede incluir espacios): ";
   getline(cin, pista);

    
    cout<<endl<<endl;
    cout<<"Recuerda, el juego consiste de 6 intentos incorrectos para que el jugador adivine la palabra" << endl << endl;
    
    for (int i = 0; i < n_letras; i++)
        cout << '_' << '\t';

    vector<char> palabra_intentada;
    for (int i = 0; i < n_letras; i++) {
        palabra_intentada.push_back('_');
    
    }
    
    vector<char> p_usada;

    for (int i = 0; intentos_incorrectos < intentos; i++) {
        string h;
        getline(cin,h);
        
        if((i>=2)){
        cout<<endl<<endl;
        cout<<"La pista es "<<pista<<endl<<endl;
        }

        if (h.length() != 1 || !es_letra_valida(h[0])|| h[0]==' ') {
            cout << "Error: La letra ingresada contiene al menos un carácter no válido." << endl;
            intentos_incorrectos++;
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl<<endl;
            
            if ((palabra_intentada != palabra_original) && (intentos_incorrectos == 6)) {
            cout <<'\t'<<"!GAME OVER¡" << endl << endl;
            cout << "La palabra correcta era :" << endl << endl;
            for (int i = 0; i < n_letras; i++) {
                cout << palabra_original[i] << '\t';
            }
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl;
            exit(0);
        }
            continue;
        }
        


        char c = toupper(h[0]);

        bool ya_usada = false;
        for (char letra : p_usada) {
            if (letra == c) {
                ya_usada = true;
                break;
            }
        }

        if (ya_usada) {
            cout << "Ya usaste la letra '" << c << "'. Intenta con otra." << endl << endl;
            intentos_incorrectos++;
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl<<endl;
            
            if ((palabra_intentada != palabra_original) && (intentos_incorrectos == 6)) {
            cout <<'\t'<<"!GAME OVER¡" << endl << endl;
            cout << "La palabra correcta era :" << endl << endl;
            for (int i = 0; i < n_letras; i++) {
                cout << palabra_original[i] << '\t';
            }
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl;
            exit(0);
        }
            continue;
        }
        
        p_usada.push_back(c);

        int j = 1;
        bool adivino = false;

        for (int i = 0; i < n_letras; i++) {
            if (palabra_original[i] == c) {
                palabra_intentada[i] = c;
                adivino = true;
                cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl<<endl;
            
            }
        }
        
        if(adivino == false){
            intentos_incorrectos++;
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl<<endl;
        }
        

        for (int t = 0; t < n_letras; t++)
            cout << palabra_intentada[t] << '\t';

        if (palabra_original == palabra_intentada) {
            cout <<endl<<'\t'<< "!Victoria¡" << endl;
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl<<endl;
            
            exit(0);
        }

        j = j + i;
        cout << "Intento número: " << j << endl << endl;

        if ((palabra_intentada != palabra_original) && (intentos_incorrectos == 6)) {
            cout <<'\t'<<"!GAME OVER¡" << endl << endl;
            cout << "La palabra correcta era :" << endl << endl;
            for (int i = 0; i < n_letras; i++) {
                cout << palabra_original[i] << '\t';
            }
            cout<<"Intentos incorrectos :"<<intentos_incorrectos<<endl;
            exit(0);
        }
    }
    
    return 0;
    
    
}

int main() {
    
    cout<<"Este es un juego de ahorcado "<<endl<<endl;
    cout<<"Opcion 1 para jugar "<<endl;
    cout<<"Opcion 2 para salir "<<endl<<endl;
    int opcion;
    cin>>opcion;
    cout<<endl;

    
    while(opcion){
    switch(opcion){
        
        case 1: 
        cout<<"Las reglas son la siguentes: "<<endl<<endl;
        cout<<'\t'<<"#1. No puedes utilizar carácteres que no estan en el abecedario español."<<endl<<endl;
        cout<<'\t'<<"#2. Al adivinar la palabra, no puedes utilizar mas de un carácter a la vez."<<endl<<endl;
        cout<<'\t'<<"#3. Al adivinar la palabra, no puedes usar espacios."<<endl<<endl;
        cout<<'\t'<<"#4. Al adivinar la palabra, no puede utilizar letras repetidas"<<endl<<endl;
        cout<<'\t'<<"#5. Todo lo anterior será contado como intento incorrecto."<<endl<<endl;
        cout<<'\t'<<"#6. Tiene 6 intentos incorrectos para adivinas la palabra."<<endl<<endl;
        cout<<'\t'<<"#7. La palabra original no puede tener espacios."<<endl<<endl;
        cout<<'\t'<<"#8. Si la palabra original no es valida, no iniciará el juego. "<<endl<<endl;
        cout<<'\t'<<"#9. Este ahorcado solo funciona con no mas de 1 palabra."<<endl<<endl;
        cout<<'\t'<<"#10. El numero de letra en la palabra orginal no debe ser mayor a 50"<<endl<<endl;
    
        run();
        break;
        case 2:
        cout<<"Salir del juego "<<endl<<endl;
        cout<<"¡Gracias por jugar nuestro primer proyecto!"<<endl;
        return 0;
        default:
        cout<<"!Opcion no es válido¡ "<<endl<<endl;
        cout<<"!Escoge atra opcion¡"<<endl<<endl;
        cin>>opcion;
    }
    }

    return 0;
}