﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace ColorsLibrary
{
    public class SortedColors
    {
        public SortedColors()
        {

        }
        public SortedDictionary<string, Color> getColors()
        {
            SortedDictionary<string, Color> colors = new SortedDictionary<string, Color>();
            colors.Add("AliceBlue", Color.AliceBlue);
            colors.Add("AntiqueWhite", Color.AntiqueWhite);
            colors.Add("Aqua", Color.Aqua);
            colors.Add("Aquamarine", Color.Aquamarine);
            colors.Add("Azure", Color.Azure);
            colors.Add("Beige", Color.Beige);
            colors.Add("Bisque", Color.Bisque);
            colors.Add("Black", Color.Black);
            colors.Add("BlanchedAlmond", Color.BlanchedAlmond);
            colors.Add("Blue", Color.Blue);
            colors.Add("BlueViolet", Color.BlueViolet);
            colors.Add("Brown", Color.Brown);
            colors.Add("BurlyWood", Color.BurlyWood);
            colors.Add("CadetBlue", Color.CadetBlue);
            colors.Add("Chartreuse", Color.Chartreuse);
            colors.Add("Chocolate", Color.Chocolate);
            colors.Add("Coral", Color.Coral);
            colors.Add("CornflowerBlue", Color.CornflowerBlue);
            colors.Add("Cornsilk", Color.Cornsilk);
            colors.Add("Crimson", Color.Crimson);
            colors.Add("Cyan", Color.Cyan);
            colors.Add("DarkBlue", Color.DarkBlue);
            colors.Add("DarkCyan", Color.DarkCyan);
            colors.Add("DarkGoldenrod", Color.DarkGoldenrod);
            colors.Add("DarkGray", Color.DarkGray);
            colors.Add("DarkGreen", Color.DarkGreen);
            colors.Add("DarkKhaki", Color.DarkKhaki);
            colors.Add("DarkMagenta", Color.DarkMagenta);
            colors.Add("DarkOliveGreen", Color.DarkOliveGreen);
            colors.Add("DarkOrange", Color.DarkOrange);
            colors.Add("DarkOrchid", Color.DarkOrchid);
            colors.Add("DarkRed", Color.DarkRed);
            colors.Add("DarkSalmon", Color.DarkSalmon);
            colors.Add("DarkSeaGreen", Color.DarkSeaGreen);
            colors.Add("DarkSlateBlue", Color.DarkSlateBlue);
            colors.Add("DarkSlateGray", Color.DarkSlateGray);
            colors.Add("DarkTurquoise", Color.DarkTurquoise);
            colors.Add("DarkViolet", Color.DarkViolet);
            colors.Add("DeepPink", Color.DeepPink);
            colors.Add("DeepSkyBlue", Color.DeepSkyBlue);
            colors.Add("DimGray", Color.DimGray);
            colors.Add("DodgerBlue", Color.DodgerBlue);
            colors.Add("Firebrick", Color.Firebrick);
            colors.Add("FloralWhite", Color.FloralWhite);
            colors.Add("ForestGreen", Color.ForestGreen);
            colors.Add("Fuchsia", Color.Fuchsia);
            colors.Add("Gainsboro", Color.Gainsboro);
            colors.Add("GhostWhite", Color.GhostWhite);
            colors.Add("Gold", Color.Gold);
            colors.Add("Goldenrod", Color.Goldenrod);
            colors.Add("Gray", Color.Gray);
            colors.Add("Green", Color.Green);
            colors.Add("GreenYellow", Color.GreenYellow);
            colors.Add("Honeydew", Color.Honeydew);
            colors.Add("HotPink", Color.HotPink);
            colors.Add("IndianRed", Color.IndianRed);
            colors.Add("Indigo", Color.Indigo);
            colors.Add("Ivory", Color.Ivory);
            colors.Add("Khaki", Color.Khaki);
            colors.Add("Lavender", Color.Lavender);
            colors.Add("LavenderBlush", Color.LavenderBlush);
            colors.Add("LawnGreen", Color.LawnGreen);
            colors.Add("LemonChiffon", Color.LemonChiffon);
            colors.Add("LightBlue", Color.LightBlue);
            colors.Add("LightCoral", Color.LightCoral);
            colors.Add("LightCyan", Color.LightCyan);
            colors.Add("LightGoldenrodYellow", Color.LightGoldenrodYellow);
            colors.Add("LightGray", Color.LightGray);
            colors.Add("LightGreen", Color.LightGreen);
            colors.Add("LightPink", Color.LightPink);
            colors.Add("LightSalmon", Color.LightSalmon);
            colors.Add("LightSeaGreen", Color.LightSeaGreen);
            colors.Add("LightSkyBlue", Color.LightSkyBlue);
            colors.Add("LightSlateGray", Color.LightSlateGray);
            colors.Add("LightSteelBlue", Color.LightSteelBlue);
            colors.Add("LightYellow", Color.LightYellow);
            colors.Add("Lime", Color.Lime);
            colors.Add("LimeGreen", Color.LimeGreen);
            colors.Add("Linen", Color.Linen);
            colors.Add("Magenta", Color.Magenta);
            colors.Add("Maroon", Color.Maroon);
            colors.Add("MediumAquamarine", Color.MediumAquamarine);
            colors.Add("MediumBlue", Color.MediumBlue);
            colors.Add("MediumOrchid", Color.MediumOrchid);
            colors.Add("MediumPurple", Color.MediumPurple);
            colors.Add("MediumSeaGreen", Color.MediumSeaGreen);
            colors.Add("MediumSlateBlue", Color.MediumSlateBlue);
            colors.Add("MediumSpringGreen", Color.MediumSpringGreen);
            colors.Add("MediumTurquoise", Color.MediumTurquoise);
            colors.Add("MediumVioletRed", Color.MediumVioletRed);
            colors.Add("MidnightBlue", Color.MidnightBlue);
            colors.Add("MintCream", Color.MintCream);
            colors.Add("MistyRose", Color.MistyRose);
            colors.Add("Moccasin", Color.Moccasin);
            colors.Add("NavajoWhite", Color.NavajoWhite);
            colors.Add("Navy", Color.Navy);
            colors.Add("OldLace", Color.OldLace);
            colors.Add("Olive", Color.Olive);
            colors.Add("OliveDrab", Color.OliveDrab);
            colors.Add("Orange", Color.Orange);
            colors.Add("OrangeRed", Color.OrangeRed);
            colors.Add("Orchid", Color.Orchid);
            colors.Add("PaleGoldenrod", Color.PaleGoldenrod);
            colors.Add("PaleGreen", Color.PaleGreen);
            colors.Add("PaleTurquoise", Color.PaleTurquoise);
            colors.Add("PaleVioletRed", Color.PaleVioletRed);
            colors.Add("PapayaWhip", Color.PapayaWhip);
            colors.Add("PeachPuff", Color.PeachPuff);
            colors.Add("Peru", Color.Peru);
            colors.Add("Pink", Color.Pink);
            colors.Add("Plum", Color.Plum);
            colors.Add("PowderBlue", Color.PowderBlue);
            colors.Add("Purple", Color.Purple);
            colors.Add("Red", Color.Red);
            colors.Add("RosyBrown", Color.RosyBrown);
            colors.Add("RoyalBlue", Color.RoyalBlue);
            colors.Add("SaddleBrown", Color.SaddleBrown);
            colors.Add("Salmon", Color.Salmon);
            colors.Add("SandyBrown", Color.SandyBrown);
            colors.Add("SeaGreen", Color.SeaGreen);
            colors.Add("SeaShell", Color.SeaShell);
            colors.Add("Sienna", Color.Sienna);
            colors.Add("Silver", Color.Silver);
            colors.Add("SkyBlue", Color.SkyBlue);
            colors.Add("SlateBlue", Color.SlateBlue);
            colors.Add("SlateGray", Color.SlateGray);
            colors.Add("Snow", Color.Snow);
            colors.Add("SpringGreen", Color.SpringGreen);
            colors.Add("SteelBlue", Color.SteelBlue);
            colors.Add("Tan", Color.Tan);
            colors.Add("Teal", Color.Teal);
            colors.Add("Thistle", Color.Thistle);
            colors.Add("Tomato", Color.Tomato);
            colors.Add("Transparent", Color.Transparent);
            colors.Add("Turquoise", Color.Turquoise);
            colors.Add("Violet", Color.Violet);
            colors.Add("Wheat", Color.Wheat);
            colors.Add("White", Color.White);
            colors.Add("WhiteSmoke", Color.WhiteSmoke);
            colors.Add("Yellow", Color.Yellow);
            colors.Add("YellowGreen", Color.YellowGreen);

            return colors;
        }    
    }
}
