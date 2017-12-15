 <?php
/**
 * @file
 * Template for a 2 column mail layout.
 */
?>
<table class="twocol <?php print $classes;?>" cellpadding="0" cellspacing="0" border="0" align="center" width="100%">

  <tr>
    <td valign="top" class="left-region"><?php print $content['left']; ?></td>
    <td valign="top" class="right-region">
      <?php print $content['right']; ?>
    </td>
  </tr>

</table>