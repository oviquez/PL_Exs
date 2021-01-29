package main;

import java.util.ArrayList;
import javax.swing.DefaultListModel;
import line.AssemblyLine;
import line.PackageLine;
import toy.Ball;
import toy.Car;
import toy.Doll;
import toy.Toy;

public class Main extends javax.swing.JFrame {
   
    private DefaultListModel assemblyLine1;
    private DefaultListModel assemblyLine2;
    private DefaultListModel assemblyLine3;
    
    private DefaultListModel packageLine1;
    private DefaultListModel packageLine2;
    private DefaultListModel packageLine3;
    
    private AssemblyLine line1;
    private AssemblyLine line2;
    private AssemblyLine line3;
    private PackageThread line4;
       
    public Main() {
        initComponents();
        
        this.assemblyLine1 = new DefaultListModel();
        this.assembly1.setModel(this.assemblyLine1);
        
        this.assemblyLine2 = new DefaultListModel();
        this.assembly2.setModel(this.assemblyLine2);
        
        this.assemblyLine3 = new DefaultListModel();
        this.assembly3.setModel(this.assemblyLine3);
        
        
        this.packageLine1 = new DefaultListModel();
        this.package1.setModel(packageLine1);
        
        this.packageLine2 = new DefaultListModel();
        this.package2.setModel(packageLine2);
        
        this.packageLine3 = new DefaultListModel(); 
        this.package3.setModel(packageLine3);
        
        this.line4= new PackageThread();
        
        this.line1 = new AssemblyLine(this.assemblyLine1,new PackageLine(packageLine1));
        this.line2 = new AssemblyLine(this.assemblyLine2,new PackageLine(packageLine2));
        this.line3 = new AssemblyLine(this.assemblyLine3,new PackageLine(packageLine3));
        
        
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        assembly1 = new javax.swing.JList<>();
        jScrollPane3 = new javax.swing.JScrollPane();
        assembly2 = new javax.swing.JList<>();
        jScrollPane4 = new javax.swing.JScrollPane();
        assembly3 = new javax.swing.JList<>();
        jScrollPane2 = new javax.swing.JScrollPane();
        package1 = new javax.swing.JList<>();
        jScrollPane5 = new javax.swing.JScrollPane();
        package2 = new javax.swing.JList<>();
        jScrollPane6 = new javax.swing.JScrollPane();
        package3 = new javax.swing.JList<>();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jScrollPane1.setViewportView(assembly1);

        jScrollPane3.setViewportView(assembly2);

        jScrollPane4.setViewportView(assembly3);

        jScrollPane2.setViewportView(package1);

        jScrollPane5.setViewportView(package2);

        jScrollPane6.setViewportView(package3);

        jButton1.setText("Generar Lotes");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                generateLots(evt);
            }
        });

        jButton2.setText("Empezar Simulacion");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                start(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(64, 64, 64)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 190, Short.MAX_VALUE)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addGap(113, 113, 113)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 195, Short.MAX_VALUE)
                    .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addComponent(jScrollPane6, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(84, 84, 84)
                .addComponent(jButton1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 199, Short.MAX_VALUE)
                .addComponent(jButton2)
                .addGap(81, 81, 81))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 101, Short.MAX_VALUE)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane5, javax.swing.GroupLayout.DEFAULT_SIZE, 93, Short.MAX_VALUE)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.DEFAULT_SIZE, 94, Short.MAX_VALUE)
                    .addComponent(jScrollPane6, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 38, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2))
                .addGap(23, 23, 23))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void generateLots(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_generateLots
        
        for(int lote = 0; lote < 3; lote++){
            for(int numero = 0;numero < 10; numero++  ){
                this.line1.addInQueue(new Doll(numero,lote));
            }
        }
        
        for(int lote = 0; lote < 3; lote++){
            for(int numero = 0;numero < 10; numero++  ){
                this.line2.addInQueue(new Car(numero,lote));
            }
        }
        
        for(int lote = 0; lote < 2; lote++){
            for(int numero = 0;numero < 10; numero++  ){
                this.line3.addInQueue(new Ball(numero,lote));
            }
        }
    }//GEN-LAST:event_generateLots

    private void start(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_start
        line1.start();
        line2.start();
        line3.start();
        //line4.start();
    }//GEN-LAST:event_start

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Main().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JList<String> assembly1;
    private javax.swing.JList<String> assembly2;
    private javax.swing.JList<String> assembly3;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JScrollPane jScrollPane6;
    private javax.swing.JList<String> package1;
    private javax.swing.JList<String> package2;
    private javax.swing.JList<String> package3;
    // End of variables declaration//GEN-END:variables
}
