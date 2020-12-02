/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package view;

import dialog.Create;
import dialog.ImageProperties;
import interfaces.ProjectManager;
import java.awt.Image;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import objects.Project;

/**
 *
 * @author Daniel
 */
public class Main extends javax.swing.JFrame implements ProjectManager {

    private ArrayList<Project> projects;
    private DefaultListModel model;
    private Project project;
    
    public Main() {
        initComponents();
        this.projects = new ArrayList<>();
        this.model = new DefaultListModel();
        listProjects.setModel(this.model);
        this.searchProjects();
    }
    
    private void searchProjects(){
        File images = new File("images/");
        File[] files = images.listFiles();
        for(int i = 0; i < files.length; i++){
            if (!files[i].isFile())
                continue;
            if (files[i].getName().contains("-postal"))
                continue;
            
            String name = files[i].getName().subSequence(0, files[i].getName().length()-4).toString();
            Project project = new Project(name);
            this.projects.add(project);
            this.model.addElement(project);
        }
        
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        listProjects = new javax.swing.JList<>();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        btnCreate = new javax.swing.JButton();
        btnPlugins = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        lblPostal = new javax.swing.JLabel();
        lblOriginal = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        listProjects.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        listProjects.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                projectSelected(evt);
            }
        });
        jScrollPane1.setViewportView(listProjects);

        jLabel1.setText("Oroginal:");

        jLabel2.setText("Postal:");

        btnCreate.setText("Crear");
        btnCreate.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                openCreateDialog(evt);
            }
        });

        btnPlugins.setText("Plugins");

        jLabel3.setText("Proyectos Creados:");

        lblPostal.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                openPostalInformation(evt);
            }
        });

        lblOriginal.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                openOriginalInfo(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(43, 43, 43)
                .addComponent(btnCreate)
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 179, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(14, 14, 14)
                        .addComponent(jLabel3)))
                .addGap(29, 29, 29)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(133, 133, 133)
                        .addComponent(jLabel2)
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(lblOriginal, javax.swing.GroupLayout.PREFERRED_SIZE, 154, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(19, 19, 19)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(btnPlugins)
                                .addGap(18, 18, 18))
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(lblPostal, javax.swing.GroupLayout.PREFERRED_SIZE, 154, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(35, 35, 35))))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 146, Short.MAX_VALUE)
                    .addComponent(lblOriginal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(lblPostal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnPlugins)
                    .addComponent(btnCreate))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    
    private void openCreateDialog(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_openCreateDialog
        this.setVisible(false);
        Create createFrame = new Create(this);
        createFrame.setVisible(true);     
    }//GEN-LAST:event_openCreateDialog

    private void projectSelected(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_projectSelected
        // TODO add your handling code here:
        int index= listProjects.getSelectedIndex();
        Project project=(Project) this.model.getElementAt(index);
        Image image = project.getImage().getImage().getScaledInstance(125, 125, java.awt.Image.SCALE_SMOOTH);
        Image postal = project.getPostal().getImage().getScaledInstance(125, 125, java.awt.Image.SCALE_SMOOTH);
        lblOriginal.setIcon(new ImageIcon(image));
        lblPostal.setIcon(new ImageIcon(postal));
        this.project = project;
    }//GEN-LAST:event_projectSelected

    private void openOriginalInfo(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_openOriginalInfo
        ImageProperties frame = new ImageProperties(this.project,false);
        frame.setVisible(true);
    }//GEN-LAST:event_openOriginalInfo

    private void openPostalInformation(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_openPostalInformation
       ImageProperties frame = new ImageProperties(this.project,true);
        frame.setVisible(true);
    }//GEN-LAST:event_openPostalInformation

    @Override
    public boolean saveProject(String name, String top, String bottom, int font,int size, File original) {
        
        for (int i = 0; i < this.projects.size(); i++){
            if(this.projects.get(i).getName().equals(name)){
                return false;
            }
        }
        
        try {
            Project project = new Project(name, top, bottom, font,size, original);
            this.projects.add(project);
            this.setVisible(true);
            this.model.addElement(project);
            return true;
        } catch (IOException ex) {
            return false;
        }
    }

    
    
    @Override
    public void cancel() {
        this.setVisible(true);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Main().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCreate;
    private javax.swing.JButton btnPlugins;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lblOriginal;
    private javax.swing.JLabel lblPostal;
    private javax.swing.JList<String> listProjects;
    // End of variables declaration//GEN-END:variables

}
