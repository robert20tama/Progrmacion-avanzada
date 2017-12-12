/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package herenciayreutilizacion;

import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent; // 1/5 action WindowListener

/**
 *
 * @author Sala2
 */
public class VPrincipal {
 Frame F;
 MenuBar MB;
 Menu M;
 MenuItem MIAbrir, MITipo;
 MyDialog MD;
 
 public VPrincipal(String str){
     F=new Frame(str);
     F.setMenuBar(MB=new MenuBar());
     MB.add(M=new Menu("Archivo"));
     M.addSeparator();
     M.add(MIAbrir=new MenuItem("Abrir"));
     M.addSeparator();
     M.add(MITipo=new MenuItem("Tipo de votacion"));
     MITipo.addActionListener(new ListenMITipo());
     M.addSeparator();
     F.addWindowListener(new WindowAdapter(){      //  3/5 Window listener
     public void WindowClosing(WindowEvent we){
         F.dispose();
         System.exit(0);
     }
     });
     F.setSize(400,300);
     F.setVisible(true);
     
     
 }
 class ListenMITipo implements ActionListener{ //  2/5 Action lsitener
     public void actionPerformed(ActionEvent ae){
      MD=new MyDialog(F);   
     }
 }
    public static void main(String[] args) {
        new VPrincipal("ventana principal");
    }
}
