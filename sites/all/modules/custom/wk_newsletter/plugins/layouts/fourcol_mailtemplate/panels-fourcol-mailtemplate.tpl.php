 <?php
/**
 * @file
 * Template for a 4 column mail layout.
 */
?>
<table class="fourcol <?php print $classes;?>" cellpadding="0" cellspacing="0" border="0" align="center" width="100%">

  <tr>
    <td valign="top" class="left-region">
      <?php print $content['left']; ?>
    </td>
    <td valign="top" class="middle-left-region">
      <?php print $content['middle_left']; ?>
    </td>
    <td valign="top" class="middle-right-region">
      <?php print $content['middle_right']; ?>
    </td>
    <td valign="top" class="right-region">
      <?php print $content['right']; ?>
    </td>
  </tr>

</table>