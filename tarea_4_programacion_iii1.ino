class Led{
public:
  Led(int _pin){
  	pin=_pin;
    pinMode(pin, OUTPUT);
  }
  //cambia el estado del Led de Encendido y apagado
  bool cambiarEstado(bool estado){
    if(estado){
    	digitalWrite(pin, HIGH);
      	delay(70);
    }else{
    	digitalWrite(pin,LOW);
      	delay(50);
    }
  }
private:
  int pin;
};
//clase de los pulsadores
class Boton{
	public:
  	  Boton(int _pin){
  		pin=_pin;
  	  }
  
  //Señal de encendido al precionar el boton
  bool PrecionarBoton(){
    if(digitalRead(pin)){     
      return 1;
    }else{
      return 0;
    }
  
  
 
  }
  private:
  	int pin;
};

Led verde(13);
Led rojo(8);
Boton botonAgregar(4);
Boton botonConsumir(2);

//variables para ingreso de datos
String nivelMax = "Ingrese el nivel Maximo: ";
String nivelMin = "Ingrese el nivel Minimo: ";
int valorMax, valorMin;
int cont=0;


void Menu(){
 Serial.println("1.Ingresar Agua");
 Serial.println("2.Consumir Agua");
 Serial.println("3.Imprimir Nivel");
}


void setup()
{
  Serial.begin(9600);
}

void loop()
{
 Serial.println(nivelMax);
  while(Serial.available() == 0){
  	
  }
  valorMax = Serial.parseInt();
  Serial.println(valorMax);
  
  Serial.println(nivelMin);
  while(Serial.available() == 0){
  	
  }
  valorMin = Serial.parseInt();  
  Serial.println(valorMin);
  
  Serial.println("-------------------------------");
  Serial.println("1. Boton Arriba para Agregar");
  Serial.println("2. Boton Abajo para consumir");
  Serial.println("-------------------------------");  
  
  
  while(cont<valorMax){
  	  if(botonAgregar.PrecionarBoton()){
        	rojo.cambiarEstado(0); 
     		Serial.println("Agregando Agua...");
        	cont ++;
    		Serial.println(cont);
     			delay(100);
      }else{
        	verde.cambiarEstado(0);	
        }
      }// 
        
    Serial.println("El tanque esta lleno");
  	Serial.print("El nivel es: ");
  	Serial.println(cont);
    verde.cambiarEstado(1);
  	
    
        while(cont<=valorMax && cont > valorMin){
        	 if(botonConsumir.PrecionarBoton()){
                verde.cambiarEstado(0);
    			Serial.println("Consumiendo Agua...");
    		    cont --;
    		    Serial.println(cont);
     			delay(100);
  		}else{ 	
            rojo.cambiarEstado(0);    					    				
  		 }
       }//
  		   	Serial.println("El tanque esta vacio");
  			Serial.print("El nivel es: ");
  			Serial.println(cont);
  		  	rojo.cambiarEstado(1);
       	
    
  
  
  
} 
  
