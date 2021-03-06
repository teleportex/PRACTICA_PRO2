/** @mainpage
    Benvingut a la especificació de la practica de PRO2!
    La solució proposada es mitjançant un diseny modular amb una clase població que
    conte els individus, una clase individu que conte la informació genetica i una clase cromosoma que conte els gens.

    Practica realitzada per Guillem Ramírez Miranda.
*/

/** @file pro2.cc
    @brief Programa principal
*/

#include "poblacio.hh"
#include "individu.hh" //redundant necesari per al diagrama
#include "especie.hh"  //redundant pero necesari per el diagrama
using namespace std;


enum string_code{
    //enum per a usar el switch amb strings
    addIn,
    reproduccion,
    escribir_arbol,
    completar_arbol,
    escribir_pob,
    escribir_gen,
    def
};


string_code hashit (string const& inString) {
    //segons la string que llegim retornem un valor de la enum per al switch
	cout<<inString;
    if (inString == "anadir_individuo") return addIn;
    if (inString == "reproduccion_sexual") return reproduccion;
    if (inString == "escribir_arbol_genealogico") return escribir_arbol;
    if (inString == "completar_arbol_genealogico") return completar_arbol;
    if (inString == "escribir_poblacion") return escribir_pob;
    if (inString == "escribir_genotipo") return escribir_gen;
    return def;
}


int main(){
    //llegim la especie i inicialitzem el sistema
    especie esp;
    esp.llegir();
    poblacio pob;
    pob.llegir(esp);
    string op;
    cin>>op;

    while(op != "acabar"){
        switch(hashit(op)){
            case addIn:{  
		            string name;
		            cin>>name;
		            cout<<" "<<name<<endl;
		            individu in;
		            in.llegir(esp);
                    if(pob.esta_individu(name)) cout<<"  error"<<endl;
		            else pob.afegir_individu(name, in);
		            break;
	          }
	          case reproduccion:{
                    string mare, pare, fil;  
		            cin>>mare>>pare>>fil;
		            cout<<" "<<mare<<" "<<pare<<" "<<fil<<endl;
		            pob.reproduir(pare, mare, fil, esp);
		            break;
	          }
    	      case escribir_arbol:{  
		            string nom;
		            cin>>nom;
		            cout<<" "<<nom<<endl;
		            if(pob.esta_individu(nom)) pob.escriure_arbre_geneologic(nom);
		            else cout<<"  error"<<endl;
		            break;
	          }
	          case completar_arbol:{
		            pob.completar_arbre();
		            break;
	         }
	          case escribir_pob:{  
                    cout<<endl;
		            pob.escriure();
		            break;
	         }
	          case escribir_gen:{  
                    string nom;
                    cin>>nom;
                    cout<<" "<<nom<<endl;
                    if(pob.esta_individu(nom)) pob.consultar_individu(nom).escriure_genotip();
                    else cout<<"  error"<<endl;
                    break;
	        }
	         default:
		            break;

	    }
	    cin>>op;
  }
  cout<<"acabar"<<endl;
}
