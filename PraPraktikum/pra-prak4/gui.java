import javax.swing.*;

public class gui{
    public static void main(String[] args) {
        String nama = JOptionPane.showInputDialog("nama : ");
        String usia = JOptionPane.showInputDialog("usia ");
        int usiaInt = Integer.parseInt(usia);
        System.out.println("Nama saya " + nama + ", usia " + usia + " tahun");
        System.exit(0);
    }
}