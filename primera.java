
package myjava.politics;

import java.awt.BorderLayout;
import java.awt.Dialog;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.GridBagLayout;
import java.awt.event.ActionListener;

public class primera implements ActionListener{//2/5 actionlistener
        Dialog D;
        Checkbox CB;
        Button BC,BA;

public primera(Frame F){

        D=new Dialog(new Frame(),"Elecciones");
	CB=new Checkbox();
        //BA=new Button("Aceptar");
	//BC=new Button("Cancel");
	
	//GridBackLayout
	D.setSize(500,500);  //(x,y) --> # de pixeles
	D.setVisible(true);
	D.setLocationRelativeTo(null);
	BC.setVisible(true);
        BA.setVisible(true);
        D.add(BA=new Button("Aceptar"));
        D.add(BC=new Button("Cancel"));
        //BC.setSize(200,200);
        BA.addActionListener(this);//3/5
        BC.addActionListener(this);//3/5
}
    public void ActionPerformed (ActionEvent ae){//4/5
    if(ae.getSource().equals(BC)){//5/5
        
    
        if(ae.getSource().equals(BA)){
            
        }
    }
   
}//end primera	

public static void main(String[] args){

new primera(new Frame());
}

    @Override
    public void actionPerformed(java.awt.event.ActionEvent ae) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
