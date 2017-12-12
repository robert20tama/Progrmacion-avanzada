/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package herenciayreutilizacion;
import java.awt.Dialog;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Frame;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Label;

/**
 *
 * @author Sala2
 */
public class MyDialog {
    Dialog D;
    Checkbox CB1,CB2,CB3,CB4,CB5,CB6;
    Button BC, BA;
    //GridBagConstraints C;
    
    //public  MyDialog(String puesto[], Label L){
    public  MyDialogFrame (f,boolean b){
      //D=new Dialog(new Frame(),"Tipo de eleccion"); 
      D=new Dialog(f,"Tipo de eleccion");
      D.setLayout(new GridBagLayout());
      GridBagConstraints c=new GridBagConstraints();
      CB1=new Checkbox("presidente");
      CB2=new Checkbox("diputado");
      CB3=new Checkbox("senador");
      CB4=new Checkbox("gobernador");
      CB5=new Checkbox("meme king");
      CB6=new Checkbox("delegado");
      BC=new Button("Cancelar deez Nutz");
      BA=new Button("Acepatar fierro pariente");
        L= new Label(" ");
     c.grids=0;
      D.setSize(300, 200);
      D.setVisible(true);
      D.setLocationRelativeTo(null);
      
      
    }
    public static void main(String[] args) {
        
    }
}
///agregar manej;
