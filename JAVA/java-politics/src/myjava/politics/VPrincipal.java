/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myjava.politics;

import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.event.WindowAdapter;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowEvent;
/**
 *
 * @author Sala2
 */
public class VPrincipal {
Frame F;
MenuBar MB;
Menu M;
MenuItem MiAbrir;
MenuItem MITipo;
        primera MD;
public VPrincipal(String str){
    F=new Frame(str);
    F.setMenuBar(MB=new MenuBar());
    MB.add(M=new Menu("Archivo"));
    M.add(MiAbrir=new MenuItem("Abrir"));
    M.addSeparator();
    M.add(MITipo=new MenuItem("Tipo de votacion"));
    MITipo.addActionListener(new ListenMITipo());
    F.addWindowListener(new WindowAdapter(){//3/5 Windowlistener
        
        public void WindowClosing(WindowEvent we){
            F.dispose();
            System.exit(0);
        }
    });
    F.setSize(400,300);
    F.setVisible(true);
    }
class ListenMITipo implements ActionListener{//2/5actionListener
@Override
public void actionPerformed(ActionEvent ae){
    MD=new primera(F);
}
}

public static void main(String arg[]){
    new VPrincipal("Ventana Principal");
}
//endClass
}
