

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class javagym extends javax.swing.JFrame {
    Connection con;
public javagym() {
        initComponents();
        CreateCon();
        this.setLocationRelativeTo(null);
        buttonGroup1.add(jRadioButton1);
         buttonGroup1.add(jRadioButton2);
          buttonGroup1.add(jRadioButton3);
           buttonGroup1.add(jRadioButton4);
            buttonGroup1.add(jRadioButton5);
             buttonGroup1.add(jRadioButton6);
              buttonGroup1.add(jRadioButton7);
               buttonGroup1.add(jRadioButton8);
                buttonGroup1.add(jRadioButton9);
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTable2 = new javax.swing.JTable();
        mlabel = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jScrollPane3 = new javax.swing.JScrollPane();
        jTable3 = new javax.swing.JTable();
        jRadioButton1 = new javax.swing.JRadioButton();
        jRadioButton2 = new javax.swing.JRadioButton();
        jRadioButton3 = new javax.swing.JRadioButton();
        jRadioButton4 = new javax.swing.JRadioButton();
        jRadioButton5 = new javax.swing.JRadioButton();
        jRadioButton6 = new javax.swing.JRadioButton();
        jRadioButton7 = new javax.swing.JRadioButton();
        jRadioButton8 = new javax.swing.JRadioButton();
        jRadioButton9 = new javax.swing.JRadioButton();
        jButton1 = new javax.swing.JButton();
        jTextField1 = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jButton3 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);
        setSize(new java.awt.Dimension(1000, 600));

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));
        jPanel1.setFont(new java.awt.Font("Arial Black", 1, 18)); // NOI18N
        jPanel1.setMinimumSize(new java.awt.Dimension(1000, 600));
        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel1.setFont(new java.awt.Font("Arial Black", 1, 36)); // NOI18N
        jLabel1.setText("Private Sessions");
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(332, 11, -1, -1));

        jLabel2.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        jLabel2.setText("coach sama");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 81, -1, -1));

        jTable1.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {"saturday", "from 03:00 to 05:00"},
                {"monday", "from 06:00 to 08:00"},
                {"wednesday", "from 09:00 to 11:00"}
            },
            new String [] {
                "days ", "session time"
            }
        ));
        jTable1.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jScrollPane1.setViewportView(jTable1);
        jTable1.getAccessibleContext().setAccessibleParent(jPanel1);

        jPanel1.add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 128, -1, 90));

        jTable2.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        jTable2.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {"saturday", "from 02:00 to 04:00"},
                {"tuesday", "from 09:00 to 11:00"},
                {"thursday", "from 10:00 to 12:00"}
            },
            new String [] {
                "days ", "session time"
            }
        ));
        jTable2.setEnabled(false);
        jTable2.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jScrollPane2.setViewportView(jTable2);
        jTable2.getAccessibleContext().setAccessibleParent(jPanel1);

        jPanel1.add(jScrollPane2, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 268, -1, 90));

        mlabel.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        mlabel.setText("coach ahmed");
        jPanel1.add(mlabel, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 221, -1, -1));

        jLabel3.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        jLabel3.setText("coach samy");
        jPanel1.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 361, -1, -1));

        jTable3.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        jTable3.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {"sunday", "from 01:00 to 03:00"},
                {"tuesday", "from 02:00 to 04:00"},
                {"friday", "from 08:00 to 10:00"}
            },
            new String [] {
                "days ", "session time "
            }
        ));
        jTable3.setEnabled(false);
        jTable3.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jScrollPane3.setViewportView(jTable3);
        jTable3.getAccessibleContext().setAccessibleParent(jPanel1);

        jPanel1.add(jScrollPane3, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 408, -1, 90));

        jRadioButton1.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton1.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton1.setText("saturday");
        jRadioButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton1ActionPerformed(evt);
            }
        });
        jPanel1.add(jRadioButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 128, -1, -1));

        jRadioButton2.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton2.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton2.setText("monday");
        jPanel1.add(jRadioButton2, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 153, -1, -1));

        jRadioButton3.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton3.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton3.setText("wednesday");
        jRadioButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton3ActionPerformed(evt);
            }
        });
        jPanel1.add(jRadioButton3, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 178, -1, -1));

        jRadioButton4.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton4.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton4.setText("saturday");
        jPanel1.add(jRadioButton4, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 268, -1, 23));

        jRadioButton5.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton5.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton5.setText("tuesday");
        jPanel1.add(jRadioButton5, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 291, -1, -1));

        jRadioButton6.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton6.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton6.setText("thursday");
        jPanel1.add(jRadioButton6, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 316, -1, -1));

        jRadioButton7.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton7.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton7.setText("sunday");
        jPanel1.add(jRadioButton7, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 410, -1, -1));

        jRadioButton8.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton8.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton8.setText("tuesday");
        jRadioButton8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton8ActionPerformed(evt);
            }
        });
        jPanel1.add(jRadioButton8, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 440, -1, -1));

        jRadioButton9.setBackground(new java.awt.Color(255, 255, 255));
        jRadioButton9.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jRadioButton9.setText("friday");
        jPanel1.add(jRadioButton9, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 470, -1, -1));

        jButton1.setBackground(new java.awt.Color(153, 153, 153));
        jButton1.setFont(new java.awt.Font("Arial Black", 1, 18)); // NOI18N
        jButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/save.jpg"))); // NOI18N
        jButton1.setText("book");
        jButton1.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 2, true));
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        jPanel1.add(jButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 510, -1, -1));

        jTextField1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField1ActionPerformed(evt);
            }
        });
        jPanel1.add(jTextField1, new org.netbeans.lib.awtextra.AbsoluteConstraints(828, 90, 145, -1));

        jLabel4.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        jLabel4.setText("Enter member's name:");
        jPanel1.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(610, 87, -1, -1));

        jLabel5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/gym_background (1).jpg"))); // NOI18N
        jPanel1.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(580, 250, 380, 140));

        jButton3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/close (1).png"))); // NOI18N
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });
        jPanel1.add(jButton3, new org.netbeans.lib.awtextra.AbsoluteConstraints(970, 0, 25, 26));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
 void CreateCon(){
        try {  
            Class.forName("com.mysql.jdbc.Driver");
             con =DriverManager.getConnection("jdbc:mysql://localhost:3306/firstDB","root","2093");
        } catch (ClassNotFoundException | SQLException ex) {
            Logger.getLogger(javagym.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    private void jRadioButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jRadioButton1ActionPerformed

    }//GEN-LAST:event_jRadioButton1ActionPerformed

    private void jRadioButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jRadioButton3ActionPerformed

    }//GEN-LAST:event_jRadioButton3ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
String name =jTextField1.getText();
              try {
 if(jRadioButton1.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
        PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(sama) VALUES(?)");
       st.setString(1, name);
st.execute();
st.close();
        }
else if(jRadioButton2.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
         PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(sama) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
 }
else if(jRadioButton3.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
         PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(sama) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
 }                                        
 else if(jRadioButton4.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
         PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(ahmed) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
 }
else if(jRadioButton5.isSelected()){
          JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE); 
          PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(ahmed) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
}
else if(jRadioButton6.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
       PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(ahmed) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
}
else if(jRadioButton7.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
       PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(samy) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
}
else if(jRadioButton8.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
              PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(samy) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
}
else if(jRadioButton9.isSelected()){
       JOptionPane.showMessageDialog(jPanel1,"booked successfully","booked successfully",JOptionPane.INFORMATION_MESSAGE);
       PreparedStatement st = con.prepareStatement("INSERT INTO privatesessions(samy) VALUES(?)");
st.setString(1, name);
st.execute();
st.close();
}
else JOptionPane.showMessageDialog(jPanel1,"you haven't selected anything","ERROR",JOptionPane.ERROR_MESSAGE);
        } catch (SQLException ex) {
            Logger.getLogger(javagym.class.getName()).log(Level.SEVERE, null, ex);
        }
       
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jTextField1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField1ActionPerformed

    }//GEN-LAST:event_jTextField1ActionPerformed

    private void jRadioButton8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jRadioButton8ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jRadioButton8ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
                    setVisible(false);
    }//GEN-LAST:event_jButton3ActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new javagym().setVisible(true);
            }
        });
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JRadioButton jRadioButton1;
    private javax.swing.JRadioButton jRadioButton2;
    private javax.swing.JRadioButton jRadioButton3;
    private javax.swing.JRadioButton jRadioButton4;
    private javax.swing.JRadioButton jRadioButton5;
    private javax.swing.JRadioButton jRadioButton6;
    private javax.swing.JRadioButton jRadioButton7;
    private javax.swing.JRadioButton jRadioButton8;
    private javax.swing.JRadioButton jRadioButton9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JTable jTable1;
    private javax.swing.JTable jTable2;
    private javax.swing.JTable jTable3;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JLabel mlabel;
    // End of variables declaration//GEN-END:variables
}
